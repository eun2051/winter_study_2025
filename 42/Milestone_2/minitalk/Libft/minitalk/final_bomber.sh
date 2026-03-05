#!/bin/bash

# 색상 정의
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
NC='\033[0m'

SERVER_PID=$(pgrep -f ./server)

if [ -z "$SERVER_PID" ]; then
    echo -e "${RED}❌ 서버를 먼저 실행하세요! (추천: valgrind ./server)${NC}"
    exit 1
fi

# Valgrind 실행 옵션 (가독성을 위해 요약 모드 사용)
VAL_OPTS="--leak-check=full --errors-for-leak-kinds=all --show-leak-kinds=all -q"

echo -e "${CYAN}==================================================${NC}"
echo -e "${CYAN}   MINITALK VALGRIND & UNICODE TOTAL ATTACK      ${NC}"
echo -e "${CYAN}==================================================${NC}"

# 테스트 함수 (전송 + 발그린드 체크)
run_v_test() {
    local TITLE=$1
    local MSG=$2
    echo -e "${YELLOW}[TEST] $TITLE${NC}"
    
    # 클라이언트에 발그린드 적용
    valgrind $VAL_OPTS ./client $SERVER_PID "$MSG"
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ Client Memory: OK${NC}"
    else
        echo -e "${RED}❌ Client Memory: LEAK OR ERROR DETECTED${NC}"
    fi
    echo "--------------------------------------------------"
    sleep 0.5
}

# 1. 1~4바이트 혼합 폭격 (유니코드 올스타)
run_v_test "Unicode Mix" "A-Z πρῶ 한글 韓國 🚀🛸🐙 👩‍👩‍👧‍👦"

# 2. 아주 긴 문자열 (Heap 압박 테스트)
LONG_STR=$(printf '💀🔥%.0s' {1..500})
run_v_test "Long Unicode (1000 bytes+)" "$LONG_STR"

# 3. 빈 문자열 및 특수 문자
run_v_test "Null & Control" $'\x01\x02\x03\x00'

# 4. 연속 고속 발사 (동기화 테스트)
echo -e "${YELLOW}[TEST] 고속 스트레스 테스트 (Valgrind 미적용으로 속도 극대화)${NC}"
for i in {1..30}
do
    ./client $SERVER_PID "Burst_$i"
    sleep 0.01
done

echo -e "\n${CYAN}✅ 모든 테스트가 끝났습니다.${NC}"
