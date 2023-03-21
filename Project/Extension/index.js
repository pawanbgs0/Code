// Log out "Button clicked!" when the user clicks the "SAVE INPUT" button

let myLeads = [];

const inputBtn = document.getElementById("input-btn")
const inputEl = document.getElementById("input-el")
const ulEl = document.getElementById("ul-el")


inputBtn.addEventListener("click", function(){
    myLeads.push(inputEl.value)
    inputEl.value = ""
    renderLeads()
})


function renderLeads()
{
    let listItems = ""
    for (let i = 0; i < myLeads.length; i++)
    {
        // listItems += "<li>" + "<a target = '_blank' href = https://" + myLeads[i] + ">" + myLeads[i] + "</a>" + "</li>"
        
        listItems += `
            <li>
                <a target = '_blank' href = "https://${myLeads[i]}"> 
                    ${myLeads[i]}
                </a>
            </li>
            `

        // create element
        // set text content
        // append to ul

        // const li = document.createElement("li")
        // li.textContent = myLeads[i]
        // ulEl.append(li)
    }
    ulEl.innerHTML = listItems
}