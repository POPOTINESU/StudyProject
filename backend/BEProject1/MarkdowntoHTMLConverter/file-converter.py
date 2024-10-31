import sys

import markdown


def convertMarkDownToHTML(markDownPath: str, HTMLPath: str) -> None:
    try:
        if markDownPath[len(markDownPath) - 2 : len(markDownPath)] == ".md":
            raise ValueError(f"Must extension is md {markDownPath}")

        with open(markDownPath, "r", encoding="utf-8") as f:
            markDownContent = f.read()
        htmlContent = markdown.markdown(markDownContent)

        with open(HTMLPath, "w", encoding="utf-8", errors="xmlcharrefreplace") as f:
            f.write(htmlContent)

        print(f"HTMLを生成しました \n {htmlContent}")
    except FileNotFoundError:
        raise FileNotFoundError(f"can not find file{markDownPath}")
    except FileExistsError:
        raise FileNotFoundError(f"file not exists{markDownPath}")


def main() -> None:
    argv = sys.argv

    markDownPath = argv[1]
    HTMLPath = argv[2]

    convertMarkDownToHTML(markDownPath, HTMLPath)


if __name__ == "__main__":
    main()
