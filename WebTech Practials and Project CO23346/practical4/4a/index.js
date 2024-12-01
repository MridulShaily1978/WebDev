
const textSize = document.getElementById('textSize');
const fontChoice = document.getElementById('fontChoice');
const textColor = document.getElementById('textColor');
const bgChoice = document.getElementById('bgChoice');
const makeBold = document.getElementById('makeBold');
const makeItalic = document.getElementById('makeItalic');
const addUnderline = document.getElementById('addUnderline');
const displayText = document.getElementById('displayText');

function applyFormatting() {
    displayText.style.fontSize = textSize.value;
    displayText.style.fontFamily = fontChoice.value;
    displayText.style.color = textColor.value;
    displayText.style.backgroundColor = bgChoice.value;
    
    
    displayText.style.fontWeight = makeBold.checked ? 'bold' : 'normal';
    displayText.style.fontStyle = makeItalic.checked ? 'italic' : 'normal';
    displayText.style.textDecoration = addUnderline.checked ? 'underline' : 'none';
}


textSize.addEventListener('change', applyFormatting);
fontChoice.addEventListener('change', applyFormatting);
textColor.addEventListener('input', applyFormatting);
bgChoice.addEventListener('input', applyFormatting);
makeBold.addEventListener('change', applyFormatting);
makeItalic.addEventListener('change', applyFormatting);
addUnderline.addEventListener('change', applyFormatting);


applyFormatting();
