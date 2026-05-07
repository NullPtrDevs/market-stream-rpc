---
name: Unit test task
about: This is template for unit tests tasks.
title: "[UT]"
labels: unit tests
assignees: ''

---

### 🎯 Scope of Testing
Specify the file, class, or function that needs to be tested.


### 🛠 Test Cases
Describe the main scenarios that must be covered:

### 📋 Requirements
- [ ] Code coverage for this module must be at least 85%.
- [ ] Use mocks for external dependencies (API, DB).
- [ ] Tests must pass in the CI/CD pipeline.

### 🔗 Context
- **Parent issue:** # (reference parent task)
- **Documentation:** [Link to logic or specs]

### 🧪 Run Command (Example for specific run)
```bash
pytest src/tests/test_example.py
```
