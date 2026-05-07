---
name: Unit test template
about: This is template for unit tests tasks.
title: "[UT]"
labels: ''
assignees: ''

---

---
name: 🧪 Unit Test Task
about: Template for writing unit tests
title: '🧪 Test: [Component/Function Name]'
labels: testing, unit-test
assignees: ''
---

### 🎯 Scope of Testing
Specify the file, class, or function that needs to be tested.
- **File:** `src/components/example.py`
- **Entity:** `calculate_total()`

### 🛠 Test Cases
Describe the main scenarios that must be covered:
- [ ] **Happy Path:** Correct behavior with valid input data.
- [ ] **Edge Cases:** Empty values, boundary numbers, `null/None`.
- [ ] **Error Handling:** Verify that expected exceptions/errors are raised.

### 📋 Requirements
- [ ] Code coverage for this module must be at least 80%.
- [ ] Use mocks for external dependencies (API, DB).
- [ ] Tests must pass in the CI/CD pipeline.

### 🔗 Context
- **Related to issue:** # (reference parent task)
- **Documentation:** [Link to logic or specs]

### 🧪 Run Command (Example)
```bash
pytest src/tests/test_example.py
```
