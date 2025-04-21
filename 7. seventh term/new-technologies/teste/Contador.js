import React, { useState } from "react";
import { Text, Button, TextInput } from "react-native";

export default (props) => {
  const [numero, setNumero] = useState(parseInt(props.inicial));

  const inc = () => setNumero(numero + parseInt(props.passo));
  const dec = () => setNumero(numero - parseInt(props.passo));
  // let numero = props.inicial

  // const inc = () => {
  //     numero++
  //     console.warn(numero)
  // }
  // const dec = () => {
  //     numero--
  //     console.warn(numero)
  // }
  const handleTextChange = (text) => {
    text.trim() !== "" && !isNaN(text)
      ? setNumero(parseInt(text))
      : setNumero(0);
  };
  return (
    <>
      <Button title="+" onPress={inc}></Button>
      <Text style={{ fontSize: 35 }}>{numero}</Text>
      <Button title="-" onPress={dec}></Button>
      <TextInput
        placeholder="iniciar"
        onChangeText={handleTextChange}
        value={numero.toString()}
      ></TextInput>
    </>
  );
};
