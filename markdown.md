# Headings
Headings are denoted using the `#` symbol followed by a space, and then followed by the text that you want to be part of the heading

# # This is the largest heading
## ## This is the second largest heading
### ### This is the third largest heading
#### #### Fourth largest heading
##### ##### Fifth heading
###### ###### Sixth heading (smallest)

# Font Styles

## Bold
__Bold text__ can be formatted using the underscore `_` character. Two underscores followed by the text to bold, immediately followed by two more underscores
```bash
# bold formatting
__text to bold__
```
Will output: __text to bold__

<br/>

## Italicized
_Italicized text_ can also be formatted using the underscore `_` character. Similar to formatting bold text, but instead of using two underscores, italicized text uses a single underscore character on both ends of the text
```bash
# italicized formatting
_text to italicize_
```
Will output: _text to italicize_

# Syntax Highlighting
To `highlight` some text, we wrap the text to be highlighted with a single backtick \`
```bash
# highlighting text
`text to highlight`
```
Will output: `text to highlight`

# Code Fences 
To outline a block of code, we wrap the code to be displayed with three backtick \` characters
```bash
# code block - remove the hashtags on the lines below
# ```bash
# code to block off
# ```
```
To include language specific highlighting, you can include the language after the first three backticks

# Lists

## Bulleted Lists
To create bulleted list, we use the hyphen `-` character to denote a list item. Indentations can be used to create nested bullet points
```bash
# bulleted list
- first bullet point
- second bullet point
	- nested bullet point
```
Will output:
- first bullet point
- second bullet point
	- nested bullet point

<br/> 

## Numbered Lists
To create a numbered list, you would include the number followed by a period `.` character
```bash
# numbered list
1. item one
2. item two
```
Will output:
1. item one
2. item two

# Hyperlinking
To hyperlink text, we use the construct `[]()`. In the square brackets, we include the text we want to be clickable. In the parenthesis, we include the URL we want the user to be redirected to upon clicking the text
```bash
# hyperlink
[take me to google](https://google.com)
```
Will output: [take me to google](https://google.com)

# Tables
To create a table, we format combinations of the pipe `|` character and the hyphen `-` character. The first row represents the column headers. The second row denotes the spacing and separates the header row from the table rows.
```bash
# table with two columns
|column 1|column 2|
|:---:|:---:|
|cell 1|cell 2|
|cell 1-2| cell 2-2|
```
Will output:
|column 1|column 2|
|:---:|:---:|
|cell 1|cell 2|
|cell 1-2|cell 2-2|

The colons in the second row are used to align the column text. Two colons on both sides of the hyphens denotes that the text should be centered. A colon on either the left or right will denote left-align and right-align respectively.
