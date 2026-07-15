# Push_swap

*This project has been created as part of the 42 curriculum by seungele.*

## Description
**Push_swap**은 두 개의 스택(Stack A, B)을 사용하여 정수 리스트를 최소한의 명령어 횟수로 정렬하는 프로젝트입니다. 이 프로그램은 정수 집합을 인자로 받아 Stack A에 저장한 뒤, 정해진 연산 규칙을 사용하여 가장 적은 단계로 오름차순 정렬을 수행하는 명령어 시퀀스를 출력합니다.

이 프로젝트의 목적은 데이터 구조(Stack)에 대한 이해를 높이고, 시간 복잡도($O(N^2)$ 또는 $O(N \log N)$)를 고려한 정렬 알고리즘을 설계하며 효율적인 최적화 기법을 학습하는 데 있습니다.

## Features
- **Greedy Algorithm**: 매 단계마다 Stack B의 요소를 Stack A의 최적 위치로 옮기기 위한 가장 적은 비용을 계산하여 실행합니다.
- **Coordinate Compression**: 입력된 정수 값들을 정렬 후 인덱스(순위)로 변환하여 처리하는 방식을 채택하여 알고리즘의 효율성을 높였습니다.
- **Optimal Instruction Choice**: `rr`과 `rrr` 같은 공통 회전 연산을 적극 활용하여 전체 명령어 개수를 획기적으로 줄였습니다.

## Instructions

### Compilation
`Makefile`을 사용하여 프로그램을 컴파일할 수 있습니다. 제공되는 규칙은 다음과 같습니다:
- `make` 또는 `make all`: `push_swap` 프로그램을 컴파일합니다.
- `make clean`: 오브젝트 파일(`.o`)을 삭제합니다.
- `make fclean`: 오브젝트 파일과 실행 파일을 모두 삭제합니다.
- `make re`: 모든 파일을 삭제 후 다시 컴파일합니다.

### Execution
컴파일된 프로그램을 다음과 같이 실행할 수 있습니다:
```bash
./push_swap 4 67 3 87 23
```
인자가 유효하지 않거나 중복될 경우, 혹은 정수 범위를 초과할 경우 Error 메시지를 출력합니다.

## Resources
- 42 Docs
    - Push_swap 과제 분석 및 가이드라인

- Algorithm References
    - Greedy Algorithm 개념 학습
### AI Usage Disclosure
- 문서화 및 Norm 최적화
    - 42의 Norminette 표준에 부합하도록 함수 구조를 정리하고, 프로젝트의 특징을 정리한 README 초안 작성 및 검토 과정에서 도움을 받았습니다.