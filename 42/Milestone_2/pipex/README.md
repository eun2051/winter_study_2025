*This project has been created as part of the 42 curriculum by seungele*

## Description
**Pipex**는 UNIX 운영체제의 핵심 메커니즘인 **Pipe(|)**와 **Redirection(<, >)**을 C 언어로 정밀하게 재구현하는 프로젝트입니다. 단순히 명령어를 실행하는 것을 넘어, 프로세스의 생명 주기와 데이터 흐름을 하이 레벨에서 제어하는 능력을 배양하는 데 목적이 있습니다.

### Core Concepts
- **Process Orchestration:** `fork()`를 사용하여 다중 자식 프로세스를 생성하고, `waitpid()`를 통해 각 프로세스의 종료 상태 및 동기화를 관리합니다.
- **Inter-Process Communication (IPC):** `pipe()` 시스템 콜을 통해 생성된 파이프라인을 프로세스 간의 데이터 통로로 활용합니다.
- **File Descriptor Manipulation:** `dup2()`를 이용해 표준 입력(stdin)과 표준 출력(stdout)을 파일이나 파이프로 리다이렉션하여 데이터의 흐름을 변경합니다.
- **Command Execution:** 환경 변수(`envp`)에서 명령어 실행 경로(`PATH`)를 파싱하고, `execve()`를 호출하여 외부 프로그램을 현재 프로세스 내에서 실행합니다.

### Technical Data Flow
이 프로그램은 쉘의 `< infile cmd1 | cmd2 > outfile` 동작을 다음과 같은 단계로 처리합니다:
1. `infile` 오픈 및 첫 번째 자식 프로세스 생성.
2. `cmd1`의 입력을 `infile`로, 출력을 파이프의 쓰기 종단(`pipe[1]`)으로 연결.
3. 두 번째 자식 프로세스 생성 및 `cmd1`의 출력을 파이프의 읽기 종단(`pipe[0]`)에서 수신.
4. `cmd2`의 결과를 `outfile`로 출력하도록 리다이렉션.

## Instructions

### 1. 컴파일 방법 (Compilation)
본 프로젝트는 GNU Make를 사용하여 빌드됩니다. 작성된 `Makefile`은 모든 종속성을 관리하며, 42 코딩 규정에 따른 엄격한 컴파일 플래그를 준수합니다.

```bash
make        # pipex 실행 파일 생성
make clean  # 빌드 과정에서 생성된 오브젝트 파일(.o) 제거
make fclean # 생성된 모든 바이너리 및 오브젝트 파일 완전 제거
make re     # fclean 후 다시 빌드 (재컴파일)
```
### 2. 프로그램 실행 형식 (Usage Syntax)
프로그램은 쉘에서 다음과 같은 문법으로 실행됩니다. 인자의 순서와 형식이 정확해야 쉘과 동일한 동작을 보장합니다.

./pipex <infile> <cmd1> <cmd2> <outfile>

infile: 데이터를 읽어올 소스 파일 (존재해야 하며 읽기 권한 필요).
cmd1: 첫 번째 자식 프로세스에서 실행할 명령어 (옵션 포함 가능).
cmd2: 두 번째 자식 프로세스에서 실행할 명령어 (옵션 포함 가능).
outfile: 최종 결과를 저장할 타겟 파일 (없으면 생성, 있으면 덮어쓰기).

### 주요 예외 처리 및 동작 상세 (Edge Cases)

Pipex는 단순 성공 사례뿐만 아니라, 다음과 같은 특수 상황에서도 쉘(bash)과 동일하게 동작하도록 설계되었습니다.

- Infile 오픈 실패 (File Not Found / Permission Denied): 입력을 읽을 수 없으므로 에러 메시지를 stderr로 출력합니다. 하지만 파이프라인 전체를 중단시키지 않고 다음 단계로 진행합니다. 첫 번째 명령어(cmd1)는 실행되지 않으며(데이터를 쓰지 않음), 두 번째 명령어(cmd2)는 빈 입력(EOF)을 받아 실행됩니다.

- 명령어 미발견 (Command Not Found): 실행하려는 명령어가 PATH 내에 존재하지 않거나 경로가 잘못된 경우 정확한 에러 메시지를 출력합니다. 쉘 표준에 따라 종료 코드 127을 반환합니다.

- 권한 부족 (Permission Denied): 명령어 실행 파일에 실행 권한이 없거나, outfile을 생성/수정할 권한이 없는 경우 적절한 시스템 에러 메시지(perror)를 보고하고 종료 코드 126 등을 처리합니다.

## Resources

### AI Usage

- 쉘 동작 정밀 시뮬레이션: 입력 파일이 없을 때 ls -l과 같이 표준 입력을 무시하는 명령어와 wc -l과 같이 표준 입력을 읽는 명령어의 차이를 분석하여, 쉘의 병렬 실행 메커니즘을 정확히 구현하는 로직 설계(에러 시 자식 프로세스 즉시 종료 등)에 도움을 받았습니다.

- 문서화 지원: 요구사항에 부합하는 README.md의 구조를 설계하고 기술적 용어를 정리하였습니다.
