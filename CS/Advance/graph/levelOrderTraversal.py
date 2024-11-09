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

    noneCounter = 0
    while not queue_obj.empty():
        queue_size = queue_obj.qsize()

        for _ in range(queue_size):
            currentNode = queue_obj.get()
            answer.append(currentNode.data if currentNode else None)

            if currentNode:
                if currentNode.left:
                    for _ in range(noneCounter):
                        queue_obj.put(None)
                    queue_obj.put(currentNode.left)
                    noneCounter = 0
                else:
                    noneCounter += 1

                if currentNode.right:
                    for _ in range(noneCounter):
                        queue_obj.put(None)
                    queue_obj.put(currentNode.right)
                    noneCounter = 0
                else:
                    noneCounter += 1

    return answer
