#  Have the function FindIntersection(strArr) read the array of strings stored in strArr which will
# contain 2 elements:
#
#   the first element will represent a list of comma-separated numbers sorted in ascending order,
#   the second element will represent a second list of comma-separated numbers (also sorted).
#
#  Your goal is to return a comma-separated string containing the numbers that occur in elements
# of strArr in sorted order. If there is no intersection, return the string false.


def FindIntersection(strArr):
    counter = {}

    for array in strArr:
        array = [int(n.strip()) for n in array.split(",") ]
        for numbers in array:
        if numbers in counter:
            counter[numbers] += 1
        else:
            counter[numbers] = 1

    target = sorted(item for item , count in counter.items() if count > 1)
    if target == []:
        return False
    else:
        return ",".join(map(str, target))
