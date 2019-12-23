import React, {useState, useRef} from "react";

function Input() {

    const [inputs, setInputs] = useState({
        name: "",
        nickname: ""
    });

    const nameInput = useRef();

    const {name, nickname} = inputs;

    const onChange = e => {
        const {name, value} = e.target;

        setInputs({
            ...inputs,
            [name]: value
        });
    };

    const onReset = () => {
        setInputs({
            name: "",
            nickname: ""
        });

        nameInput.current.focus();
    };


    
    return (
        <div>
            <input onChange={onChange} name="name" placeholder="이름" value={name} ref={nameInput} />
            <input onChange={onChange} name="nickname" placeholder="닉네임" value={nickname} />
            <button onClick={onReset}>초기화</button>
            <div>
                <b>
                    이름: {name}<br />
                    닉네임: {nickname}
                </b>
            </div>
        </div>
    )
}

export default Input;