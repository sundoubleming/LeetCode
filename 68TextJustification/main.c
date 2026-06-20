#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fullRow(char** words, int wordsSize, int maxWidth, int* offset) {
	char* row = malloc(sizeof(char) * maxWidth + 1);
	memset(row, ' ', maxWidth);
	row[maxWidth] = '\0';
	size_t len = 0;
	int start = *offset;
	int end = *offset;
	int wordsLength = 0;
	while (end < wordsSize && len + strlen(words[end]) <= maxWidth) {
		wordsLength += strlen(words[end]);
		len += strlen(words[end]);
		// 算一个空格
		if (len + 1 <= maxWidth) {
			++len;
		} else {
			break;
		}
		++end;
	}
	// 返回给调用者用户下一次迭代
	*offset = end;

	int spaceSize = maxWidth - wordsLength;
	// 不止一个word
	if (end - start > 1) {
		int size = spaceSize / (end - start - 1);
		int extra = spaceSize % (end - start - 1);
		int roffset = 0;
		for (int idx = start; idx < end; ++idx) {
			memcpy(row + roffset, words[idx],  strlen(words[idx]));
			roffset += strlen(words[idx]);
			if ((idx - start) < extra) {
				roffset += size + 1;
			} else {
				roffset += size;
			}
		}
	} else {
		memcpy(row, words[start], strlen(words[start]));
	}
	return row;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
	int idx = 0;
	char** ret = malloc(sizeof(char *) * 300);
	int offset = 0;
	for (; idx < 300; ++idx) {
		ret[idx] = fullRow(words, wordsSize, maxWidth, &offset);
		if (offset >= wordsSize) {
			break;
		}
	}

	*returnSize = idx + 1;
	return ret;
}

int main(int argc, char **argv) {
	if (argc <= 2) {
		printf("Usage: ./main This is an example of test justification 16\n");
		return -1;
	}
	int wordsSize = argc - 2;
	char **words = malloc(sizeof(char *) * wordsSize);
	for (int idx = 0; idx < wordsSize; ++idx) {
		words[idx] = argv[idx + 1];
	}
	int maxWidth = atoi(argv[argc - 1]);
	int returnSize = 0;
	char **ret = fullJustify(words, wordsSize, maxWidth, &returnSize);
	for (int idx = 0; idx < returnSize; ++idx) {
		printf("%s\n", ret[idx]);
	}
	return 0;
}
