---
allowed-tools: Bash(gh pr checkout:*), Bash(git merge:*), Bash(git status:*), Bash(gh pr diff:*), Bash(ls:*), Bash(grep:*), Task
argument-hint: <pr-id>
description: Review pull request by checking out, merging with develop, and analyzing
---

Checkout PR #$1, merge with develop, check for migration conflicts, and review:

1. Run `gh pr checkout $1`
2. Run `git merge origin/develop`
3. Check the migrations/ folder for conflicting migrations between this PR and develop:
   - List migrations in the current branch and check for numbering conflicts
   - If there are migration files with the same number from both branches, resolve by favoring develop's numbering (renumber the PR's migrations to the next available numbers)
   - Ensure migrations follow the sequential numbering pattern (e.g., 152_*.sql, 153_*.sql, etc.)
4. Run `gh pr diff $1` to see the changes
5. Use researcher agent to review the code changes