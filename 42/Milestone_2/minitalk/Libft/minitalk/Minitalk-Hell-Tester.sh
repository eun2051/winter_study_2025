#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

SERVER_PID=$(pgrep -f ./server)

if [ -z "$SERVER_PID" ]; then
    echo -e "${RED}❌ 서버를 먼저 실행하세요!${NC}"
    exit 1
fi

echo -e "${YELLOW}=== 😈 MINITALK HELL TESTER V2 ===${NC}"

# [TEST 2] 대용량 텍스트 재도전 (이제 Valgrind를 client에 직접 겁니다)
echo -e "\n${BLUE}[TEST 2] 10,000자 전송 + Client 메모리 검사${NC}"
RANDOM_STR=$(LC_ALL=C tr -dc 'A-Za-z0-9' < /dev/urandom | head -c 10000)
# 클라이언트에 직접 발그린드를 걸어서 실행합니다.
valgrind --leak-check=full ./client $SERVER_PID "$RANDOM_STR"
sleep 2

# [TEST 4] 초고속 연속 발사 (sleep 명령어 수정)
echo -e "\n${BLUE}[TEST 4] 0.05초 간격 50회 초고속 발사${NC}"
for i in {1..50}
do
   # 출력 메시지를 짧게 해서 서버의 부하를 테스트합니다.
   ./client $SERVER_PID "S_$i"
   sleep 0.05  # usleep 대신 sleep 사용 (초 단위이므로 0.05가 약 50ms)
done

echo -e "\n${GREEN}✅ 지옥 테스트 완료! 서버 터미널의 출력이 깨졌는지 확인하세요.${NC}"
