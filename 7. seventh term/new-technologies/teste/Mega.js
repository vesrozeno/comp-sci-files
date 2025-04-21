import React from "react";
import { Text, TextInput, Button, StyleSheet, View } from "react-native";
import MegaNumero from "./MegaNumero";

export default class Mega extends React.Component {
  state = {
    qtdNumeros: this.props.qtdNumeros,
    numeros: [],
  };
  alterarQtdNumeros(qtde) {
    this.setState({ qtdNumeros: qtde });
  }
  gerarNumeroNaoContido = (nums) => {
    const novo = parseInt(Math.random() * 60) + 1;
    return nums.includes(novo) ? this.gerarNumeroNaoContido(nums) : novo;
  };
  gerarNumeros = () => {
    // const numeros = Array(this.state.qtdNumeros)
    //   .fill()
    //   .reduce((n) => [...n, this.gerarNumeroNaoContido(n)], [])
    //   .sort((a, b) => a - b);
    // this.setState({ numeros });
    const { qtdNumeros } = this.state;
    const numeros = [];
    for (let i = 0; i < qtdNumeros; i++) {
      numeros.push(this.gerarNumeroNaoContido(numeros));
    }
    numeros.sort((a, b) => a - b);
    this.setState({ numeros });
  };
  exibirNumeros = () => {
    const nums = this.state.numeros;
    return nums.map((n) => {
      return <MegaNumero key={n} num={n} />;
    });
  };

  render() {
    return (
      <>
        <Text style={{ fontWeight: "bold", fontSize: 18, margin: 25 }}>
          Gerador de Mega Sena {this.setState.qtdNumeros}
        </Text>
        <TextInput
          keyboardType="numeric"
          style={{
            borderBottomWidth: 2,
            width: 250,
            textAlign: "center",
            margin: 10,
          }}
          placeholderTextColor={"black"}
          placeholder="qt. de números"
          value={this.state.qtdNumeros}
          onChangeText={(qtde) => this.alterarQtdNumeros(qtde)}
        />
        <Button title="Gerar Números" onPress={this.gerarNumeros} />
        {/* <Text>{this.state.numeros.join(" | ")}</Text> */}
        <View style={style.numeros}>{this.exibirNumeros()}</View>
      </>
    );
  }
}
const style = StyleSheet.create({
  numeros: {
    marginTop: 20,
    flexDirection: "row",
    flexWrap: "wrap",
    justifyContent: "center",
  },
});
