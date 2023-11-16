# Push Swap Project - 42 Coding School 🚀

🔗 [Watch this projects on my channel](https://youtu.be/2-1UbB4wlWU)
---

## Introduction

Welcome to the Push Swap project, a challenging endeavor of sorting data on a stack using a limited set of operations.

---

## **Mandatory Part**:

### **V.1 Rules & Operations**

You are provided with two stacks named `a` and `b`.

- **Initial Setup**:
  - Stack `a` contains a random set of non-duplicated, negative and/or positive numbers.
  - Stack `b` starts empty.

- **Objective**: 
  - Sort the numbers in stack `a` in ascending order.

- **Available Operations**:

  - `sa` (swap a): Swap the top two elements of stack `a`. No effect if the stack contains one or no elements.
  - `sb` (swap b): Swap the top two elements of stack `b`. No effect if the stack contains one or no elements.
  - `ss`: Execute both `sa` and `sb` simultaneously.
  - `pa` (push a): Take the top element of stack `b` and place it at the top of stack `a`. No effect if `b` is empty.
  - `pb` (push b): Take the top element of stack `a` and place it at the top of stack `b`. No effect if `a` is empty.
  - `ra` (rotate a): Shift all elements of stack `a` up by one. The first element becomes the last.
  - `rb` (rotate b): Shift all elements of stack `b` up by one. The first element becomes the last.
  - `rr`: Execute both `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of stack `a` down by one. The last element becomes the first.
  - `rrb` (reverse rotate b): Shift all elements of stack `b` down by one. The last element becomes the first.
  - `rrr`: Execute both `rra` and `rrb` simultaneously.

---

### **V.2 Example**

To better understand these operations, consider a detailed example to illustrate the effect of these instructions on a random list of integers. (Here, you might want to provide the example and its step-by-step demonstration.)
<img width="606" alt="Screen Shot 2023-06-10 at 12 07 27 PM" src="https://github.com/kieubo90/push_swap/assets/88286643/36050b79-8b8e-4b8d-b023-5750021cf6d6">
---

