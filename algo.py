def smallest_number_with_digit_sum(N):
    # Start with 1000 (smallest 4-digit number)
    for number in range(1000, 10000):
        if sum(map(int, str(number))) == N:
            return number
    return None  # If no such number exists (unlikely)

# Example
N = 10
print(f"Smallest 4-digit number with digit sum {N}: {smallest_number_with_digit_sum(N)}")