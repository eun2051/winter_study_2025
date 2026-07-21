*This project has been created as part of the 42 curriculum by seungele.*

# 🎮 so_long

## 📝 Description
**so_long**은 42 커리큘럼의 Milestone 2 프로젝트로, MiniLibX 라이브러리를 사용하여 구현한 기초적인 **2차원 탑다운(Top-down) 게임**입니다. 

이 프로젝트의 목표는 맵 파일(`.ber`)을 파싱하고, 그래픽 라이브러리를 제어하며, 윈도우 관리 및 이벤트 처리(키보드 입력, 마우스 클릭 등)를 익히는 것입니다. 플레이어는 맵 상의 모든 수집품(Collectible)을 모은 뒤, 최소한의 움직임으로 탈출구(Exit)에 도달해야 합니다.

### **Game Goal**
- 맵에 있는 모든 수집품(C)을 획득합니다.
- 모든 아이템을 모은 후, 탈출구(E)를 통해 가장 짧은 경로로 탈출합니다.

## 🛠️ Instructions

### **Compilation**
해당 프로젝트는 `Makefile`을 포함하고 있습니다. 터미널에서 다음 명령어를 입력하여 컴파일합니다.
```bash
make
./so_long ./map/-
```
- Execution
    컴파일 후, 실행파일 뒤에 유효한 맵 파일 경로(.ber)를 인자로 넣어 실행합니다.
- Controls
    - W / A / S / D : 플레이어 이동 (상, 하 , 좌, 우)
    - ESC : 게임 종료 및 창 닫기 (Clean exit)
    - 창의 'X' 버튼 클릭 : 게임 종료 및 창 닫기 (Clean exit)

## 🚀 Features & Technical Choices
1. Map Validation (Flood Fill Algorithm)
단순히 요소의 개수만 체크하는 것이 아니라, 실제 게임이 클리어 가능한지 확인하기 위해 Flood Fill 알고리즘을 사용했습니다.

- Deep Copy: 원본 맵 데이터를 보호하기 위해 ft_strdup을 사용하여 맵 복사본(game->copy)을 생성했습니다.

- Path Verification: 플레이어 시작점('P')에서 출발하여 벽('1')을 제외한 모든 경로를 재귀적으로 탐색하며 방문 표시('v')를 남깁니다. 탐색 후 도달하지 못한 아이템('C')이나 탈출구('E')가 있다면 Error\n 메시지와 함께 프로그램을 종료합니다.

2. Graphics Management (MiniLibX)
- XPM Images: MiniLibX의 기능을 사용하여 .xpm 파일을 윈도우 창에 렌더링했습니다.

- Smooth Window Management: 윈도우 최소화, 창 전환 등의 상황에서도 깨지지 않고 부드럽게 작동하도록 관리했습니다.

- Top-down 2D View: 64x64 픽셀 단위의 스프라이트를 배치하여 직관적인 2D 뷰를 구현했습니다.

3. Event & Error Handling
- Move Counter: 플레이어가 움직일 때마다 터미널(Shell)에 현재 이동 횟수를 실시간으로 출력합니다.

- Strict Parsing: 맵이 직사각형이 아니거나, 벽으로 둘러싸여 있지 않거나, 필수 요소(P, E, C)의 개수가 잘못된 경우 명확한 에러 메시지를 출력하고 메모리를 안전하게 해제한 뒤 종료합니다.

## 📚 Resources

- MiniLibX 공식 문서
- [text](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#initialization-functions)

## AI Usage 
본 프로젝트의 최적화 및 README 작성 과정에서 AI를 다음과 같은 작업에 활용하였습니다.