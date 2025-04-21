import React, { useState } from "react";
import { Text, Button, TextInput } from "react-native";
import ContadorDisplay from "./ContadorDisplay";
import ContadorBotoes from "./ContadorBotoes";

export default (props) => {
  const [num, setNum] = useState(0);
  return (
    <>
      <ContadorDisplay num={num}></ContadorDisplay>
      <ContadorBotoes
        inc={() => setNum(num + parseInt(1))}
        dec={() => setNum(num - parseInt(1))}
      ></ContadorBotoes>
    </>
  );
};
