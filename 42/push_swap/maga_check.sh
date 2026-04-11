#!/bin/bash

# 색상 설정
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# 테스트 실행 함수
# $1: 데이터 개수, $2: 테스트 횟수, $3: 만점 기준(Steps)
run_bulk_test() {
    local count=$1
    local iterations=$2
    local limit=$3

    echo -e "${BLUE}==========================================${NC}"
    echo -e "${YELLOW}>>> Testing $count elements ($iterations times)${NC}"
    echo -e "${BLUE}==========================================${NC}"
    echo -e " RUN |  STEPS  | RESULT"
    echo "-----------------------"

    for ((i=1; i<=iterations; i++))
    do
        # 중복 없는 랜덤 숫자 생성
        ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-5000, 5000), $count))))")
        
        # push_swap 실행
        OUTPUT=$(./push_swap $ARG)
        STEPS=$(echo "$OUTPUT" | sed '/^$/d' | wc -l)
        
        # checker_Mac 검증
        CHECK_RES=$(echo "$OUTPUT" | ./checker_Mac $ARG)

        # 결과 출력 (성공 시 녹색 OK)
        if [ "$CHECK_RES" == "OK" ]; then
            if [ $STEPS -le $limit ]; then
                printf " %02d  |  %5d  | ${GREEN}OK (Full Marks)${NC}\n" "$i" "$STEPS"
            else
                printf " %02d  |  %5d  | ${GREEN}OK${NC}\n" "$i" "$STEPS"
            fi
        else
            printf " %02d  |  %5d  | ${RED}KO${NC}\n" "$i" "$STEPS"
        fi
    done
    echo ""
}

# 파일 존재 확인
if [ ! -f "./push_swap" ] || [ ! -f "./checker_Mac" ]; then
    echo -e "${RED}Error: ./push_swap 또는 ./checker_Mac를 찾을 수 없습니다.${NC}"
    exit 1
fi

# 1. 100개 테스트 (100회 반복, 만점 기준 700)
run_bulk_test 100 100 700

# 2. 500개 테스트 (100회 반복, 만점 기준 5500)
run_bulk_test 500 100 5500