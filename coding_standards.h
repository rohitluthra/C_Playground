#ifndef C_PLAYGROUND_CODING_STANDARDS_H
#define C_PLAYGROUND_CODING_STANDARDS_H

/*************************************************************************************************************
 * Write comments like your future self will thank you.
 *************************************************************************************************************/

/**************************************************************************************************************
    Goal of Standards
        1. Readability      : Anybody can determine how the software is designed and expected to execute.
        2. Maintainability  : Adaptable and east to modify
        3. Reliability      : Compile-able and executable on different platform with minor changes.
        4. Consistency      : Share same principles over the project directory.
***************************************************************************************************************/

/**************************************************************************************************************
    Order of information in source code:
        1. Module header block.
        2. Include Files.
        3. Declarations (defined constants, macros and types)
        4. Local prototypes.
        5. Module Data.
        6. Exported functions.
        7. Local Function bodies.
***************************************************************************************************************/

/**************************************************************************************************************
    - Non negative values are declared unsigned.
    - Do not embed if statements with IF ELSE.
    - Private Module should be static.
    - Comments blocks for defines.
    - Enum must have its own name first. Eg: ERROR_STATUS_SUCCESS
        - Its typedef must be in all caps.
        - Must have UNKNOWN as last element.
***************************************************************************************************************/

/**************************************************************************************************************
Function Prototype Example
***************************************************************************************************************
Function Name:
***************************************************************************************************************
Detailed Description:
    Starts over here, describes:
        - Overall use of function.
        - Fundamental equation and primary operation.
        - Technical Basis.
        - Error Handling.
***************************************************************************************************************
Interface Description:
    symbol name         -   [symbol description]
                            [symbol type or variable information, eg: pointer, global, stack, static, volatile.]
                            [symbol details, eg: numerical value with [unit, range or resolution], memory storage
                            [flash, eeprom, disk, etc.]]
    <return value>      -   description
                            function return, TYPE
    parameter name      -   meaning
                            function input/output, Pointer? , TYPE

***************************************************************************************************************/

/**************************************************************************************************************
 Inside Function:
    - Variable name should be:
        - Pointers should be prefixed with "_ptr" or "P".
        - Lowercase, underscore allowed.
        - Use volatile or caching, if needed.

    - Endline comments are allowed.
    - Add as much comments as possible.
    - Replace inline values with defined constants.
    - Keep code aligned.
    - No extra spaces.

    EG:
        static function_name(void) {

        } [end function _________]

    [end module _______.c]

****************************************************************************************************************/

#endif //C_PLAYGROUND_CODING_STANDARDS_H
