//
// Created by jm on 2024/3/8.
//

#ifndef DATASTRUCTURE_INCLUDE_LLIST_STATUS_CODE_H_
#define DATASTRUCTURE_INCLUDE_LLIST_STATUS_CODE_H_

typedef enum ListStatusCode {
  LS_OK = 0,        // 操作正常完成
  LS_ERR = 1,       // 操作出现异常
  LS_EMPTY = 2,     // 链表为空
  LS_ERR_INDEX = 3, // 错误的索引
  LS_UNKNOWN = 999  // 未知异常
} ListStatusCode;

#endif //DATASTRUCTURE_INCLUDE_LLIST_STATUS_CODE_H_
