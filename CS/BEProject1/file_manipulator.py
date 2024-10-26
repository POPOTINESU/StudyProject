import sys


class FileManipulator:
    def __init__(self) -> None:
        self.validator = FileValidate

    def create_reverse_content(self, input_path: str, output_path: str) -> str:
        self.validator.path(input_path)
        self.validator.path(output_path)

        contents = self._read_contents(input_path)
        reversedContent = contents[::-1]

        with open(output_path, "w", encoding="utf-8") as f:
            f.write(reversedContent)

        return reversedContent

    def copy_content(self, input_path: str, output_path: str) -> str:
        self.validator.path(input_path)
        self.validator.path(output_path)

        contents = self._read_contents(input_path)
        with open(output_path, "w", encoding="utf-8") as f:
            f.write(contents)

        return contents

    def create_duplicate_content(self, input_path: str, duplicate_count: int) -> str:
        self.validator.path(input_path)
        self.validator.count(duplicate_count)

        contents = self._read_contents(input_path)
        with open(input_path, "a") as f:
            for _ in range(duplicate_count):
                f.write(contents)

        return f"{contents} * {duplicate_count}"

    def replace_string(
        self, input_path: str, target_string: str, replace_string: str
    ) -> str:
        self.validator.str(target_string)
        self.validator.str(replace_string, null=True)

        contents = self._read_contents(input_path)
        replacedContents = contents.replace(target_string, replace_string)
        with open(input_path, "w", encoding="utf-8") as f:
            f.write(replacedContents)

        return replacedContents

    def _read_contents(self, path: str) -> str:
        try:
            with open(path) as f:
                contents = f.read()
            return contents
        except FileNotFoundError:
            raise FileNotFoundError(f"Can not found file: {path}")


class FileValidate:
    @staticmethod
    def path(path: str) -> bool:
        MIN_PATH_LENGTH = 5

        if len(path) < MIN_PATH_LENGTH:
            raise ValueError(f"Not correct path name: {path}")

        # 今回は.txt演算子のみを許可する
        extension = path[len(path) - 4 : len(path)]
        if not extension == ".txt":
            raise ValueError(f"Not correct path extension: {path}")

        return True

    @staticmethod
    def count(count: int) -> bool:
        if count > 0:
            return True
        else:
            raise ValueError("Must count is grater than zero")

    @staticmethod
    def str(string: str, null=False) -> bool:
        if not null and len(string) == 0:
            raise ValueError("Must not input empty string")
        return True


def convertStringToInt(string: str) -> int:
    try:
        return int(string)
    except ValueError:
        raise ValueError("Must input natural number")


def main(command) -> None:
    fileManipulator = FileManipulator()

    if command == "reverse":
        input_path = sys.argv[2]
        output_path = sys.argv[3]

        print(fileManipulator.create_reverse_content(input_path, output_path))

    elif command == "copy":
        input_path = sys.argv[2]
        output_path = sys.argv[3]

        print(fileManipulator.copy_content(input_path, output_path))

    elif command == "duplicate-contents":
        input_path = sys.argv[2]
        duplicate_count = convertStringToInt(sys.argv[3])

        print(fileManipulator.create_duplicate_content(input_path, duplicate_count))

    elif command == "replace-string":
        input_path = sys.argv[2]
        target_string = sys.argv[3]
        replace_string = sys.argv[4]

        print(fileManipulator.replace_string(input_path, target_string, replace_string))


if __name__ == "__main__":
    command = sys.argv[1]
    main(command)
