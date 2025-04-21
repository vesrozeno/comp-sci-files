import { StatusBar } from "expo-status-bar";
import React, { useState } from "react";
import { StyleSheet, Text, View, Button } from "react-native";
import MyButton from "./MyButton";
import Contador from "./Contador";
import ListaProdutos from "./ListaProdutos";
import produtos from "./produtos";
import Alerta from "./Alerta";
import Pai from "./Pai";
import ContadorPai from "./ContadorPai";
import CompProp from "./CompProp";
import Card from "./Card.js";
import Familia from "./Familia";
import Membro from "./Membro";
import UsuarioLogado from "./UsuarioLogado.js";
import FlexBox from "./FlexBox.js";
import Mega from "./Mega.js";
import Stack from "./MyStack.js";
import MyStack from "./MyStack.js";
import Tab from "./Tab.js";
import { SafeAreaView } from "react-native-safe-area-context";
import { NavigationContainer } from "@react-navigation/native";

export default function App() {
  const [mostrarMsg, setMostrarMsg] = React.useState(false);
  return (
    <View style={styles.container}>
      {/* <Text>teste</Text>
      <StatusBar style="auto" />
      <MyButton label={'botão'} onClick={() => { console.warn('daora') }}></MyButton> */}
      {/* <Contador inicial={1} passo={1}></Contador> */}
      {/* <Button title={'Mostra Lista'}
        onPress={() => { setMostrarMsg(!mostrarMsg) }}></Button>
        {mostrarMsg && <ListaProdutos produtos={produtos}></ListaProdutos>} */}
      {/* <Alerta></Alerta> */}
      {/* <Pai></Pai> */}
      {/* <ContadorPai></ContadorPai> */}
      {/* <CompProp>
        <Text>Texto</Text>
        <Text>Texto</Text>
      </CompProp> */}
      {/* <Membro nome={"jose"} sobrenome={"aldo"}></Membro>
      <Card>
        <Text>texto</Text>
      </Card> */}
      {/* <Card>
        <Familia>
          <Membro nome={"jose"} sobrenome={"aldo"}></Membro>
          <Membro nome={"anderson"} sobrenome={"silva"}></Membro>
          <Membro nome={"vitor"} sobrenome={"belfort"}></Membro>
          <Membro nome={"charles"} sobrenome={"do bronx"}></Membro>
        </Familia>
      </Card>
      <UsuarioLogado
        usuario={{ nome: "ConorMcGregor", email: "conor@ig.com" }}
      ></UsuarioLogado>
      <UsuarioLogado usuario={{ email: "joao@ig.com" }}></UsuarioLogado>
      <UsuarioLogado usuario={{}}></UsuarioLogado> */}
      {/* <FlexBox></FlexBox> */}
      {/* <Mega></Mega> */}
      <SafeAreaView style={{ flex: 1 }}>
        <NavigationContainer>
          <Tab></Tab>
        </NavigationContainer>
      </SafeAreaView>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#FFF",
    alignItems: "center",
    justifyContent: "center",
  },
});
