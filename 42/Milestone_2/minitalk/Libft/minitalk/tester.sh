#!/bin/bash

# 색상 정의
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# 1. 서버 실행 확인
SERVER_PID=$(pgrep server)

if [ -z "$SERVER_PID" ]; then
    echo -e "${RED}오류: server가 실행 중이지 않습니다. 별도의 터미널에서 ./server를 실행하세요.${NC}"
    exit 1
fi

echo -e "${GREEN}테스트 시작! (Server PID: $SERVER_PID)${NC}"
echo "-----------------------------------------------"

# 테스트 함수
run_test() {
    local TYPE=$1
    local MESSAGE=$2
    echo -e "테스트 중: [${TYPE}]"
    ./client $SERVER_PID "$MESSAGE"
    sleep 0.5 # 서버가 출력할 시간을 주기 위한 여유
    echo -e "\n-----------------------------------------------"
}

# 1. 기본 문자열
run_test "Basic" "Hello, 42 World!"

# 2. 유니코드 및 이모지 (보너스 체크)
run_test "Unicode/Emoji" "안녕하세요 🇰🇷 🚀 🍎 ✨"

# 3. 공백 및 특수문자
run_test "Special Chars" "   !@#$%^&*()_+=-[]{};':\",./<>?   "

# 4. 매우 긴 문장 (속도 및 누수 체크)
LONG_STR=$(printf 'A%.0s' {1..500})
run_test "Long String (500 chars)" "$LONG_STR"

echo -e "${GREEN}모든 테스트 케이스 전송 완료!${NC}"
echo "서버 터미널에서 출력이 일치하는지 확인하세요."
