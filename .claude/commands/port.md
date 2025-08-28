---
description: Port functionality from source to destination with alternating research and execution steps
argument-hint: <source_folder> <destination_folder> <instructions>
---

# Parse the three arguments
SOURCE_FOLDER=$1
DESTINATION_FOLDER=$2
INSTRUCTIONS=$3

# Check if we're already on a specialized branch, create one if not
CURRENT_BRANCH=$(git branch --show-current)
if [[ "$CURRENT_BRANCH" == "main" || "$CURRENT_BRANCH" == "master" || "$CURRENT_BRANCH" == "develop" ]]; then
  git checkout -b "port-$(basename "$SOURCE_FOLDER")-to-$(basename "$DESTINATION_FOLDER")-$(date +%Y%m%d)"
else
  echo "Already on specialized branch: $CURRENT_BRANCH"
fi

# Initial setup and planning phase
# CRITICAL: Create and maintain a comprehensive todolist throughout!
Use researcher agent to analyze both projects and create initial todolist:

1. Research source project structure and identify relevant components for: $INSTRUCTIONS
2. Research destination project structure and determine integration points
3. MANDATORY: Create detailed todolist with TodoWrite tool following the 4-mode pattern
   - The todolist is your PRIMARY tracking mechanism
   - Keep it updated CONSTANTLY throughout the porting process

# Execute the porting process with 4 alternating modes:

For each porting task, follow this sequence:

Mode 1 - Research Source:
  Use researcher to deeply understand the source implementation
  - Mark current research task as in_progress in todolist
  - Analyze code structure, dependencies, patterns
  - Identify what needs to be ported from $SOURCE_FOLDER
  - Document findings and requirements
  - Update todolist with specific components to port

Mode 2 - Research Destination: 
  Use researcher to plan integration into destination
  - Continue tracking progress in todolist
  - Analyze $DESTINATION_FOLDER structure and conventions
  - Identify where and how to integrate the ported code
  - Plan necessary adaptations and modifications
  - Update todolist with integration points discovered

Mode 3 - Execute Changes:
  Use executioner to implement the port
  - Mark execution tasks as in_progress in todolist
  - Make precise code modifications
  - Adapt to destination conventions and patterns
  - Ensure proper integration
  - Mark completed porting tasks as done IMMEDIATELY

Mode 4 - Research, Adjust & Commit:
  MANDATORY: Full todolist update and maintenance
  - Use researcher to verify implementation quality
  - Commit current porting progress with descriptive message
  - Mark ALL completed items as done in todolist
  - Add ANY new tasks discovered during porting
  - Remove obsolete tasks that are no longer needed
  - Ensure todolist accurately reflects remaining work
  - Maintain the 4-mode pattern for remaining tasks
  - Continue cycle if more work needed
  - NEVER skip this todolist update - it's CRITICAL for tracking

# Quality assurance and final commit
Final research step to validate the complete port:
- Verify all requirements from $INSTRUCTIONS are met
- Check for consistency and proper integration
- Identify any issues or improvements needed
- Make final commit summarizing the completed port

Think carefully at each step! The goal is systematic, thorough porting from $SOURCE_FOLDER to $DESTINATION_FOLDER following $INSTRUCTIONS!

REMEMBER: The todolist is your primary tool for success - keep it updated CONSTANTLY throughout all 4 modes, not just during adjustment phases!