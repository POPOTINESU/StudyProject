import queue


class BinaryTree:
    def __init__(self, data, left=None, right=None) -> None:
        self.data = data
        self.left = left
        self.right = right


def levelOrderTraversal(root) -> list:
    # 関数を完成させてください
    answer = []
    queue_obj = queue.Queue()
    queue_obj.put(root)

    while not queue_obj.empty():
        queue_size = queue_obj.qsize()

        for _ in range(queue_size):
            currentNode = queue_obj.get()
            answer.append(currentNode.data if currentNode else "null")
        
            if currentNode:
                queue_obj.put(currentNode.left)
                queue_obj.put(currentNode.right)
    
    while (len(answer)>0 and answer[len(answer)-1] == "null"):
        answer.pop()
    
    # 一度にnullを切り取る方が効率がいい
    null_count= 0
    for value in answer[::-1]:
        if value == "null":
            null_count += 1
        else:
            break
    
    return answer[0:len(answer)-null_count]
