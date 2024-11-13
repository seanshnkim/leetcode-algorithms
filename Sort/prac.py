def solution(array, commands):
    answer = []
    
    for comm in commands:
        start, end, i = comm[0], comm[1], comm[2]
        
        start -= 1
        i -= 1
        answer.append(sorted(array[start:end])[i])
        
            
    return answer