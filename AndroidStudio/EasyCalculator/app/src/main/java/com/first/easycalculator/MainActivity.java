package com.first.easycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.view.View;
import android.widget.TextView;

import com.google.android.material.button.MaterialButton;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;

import java.util.Stack;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TextView resultTv, solutionTv;
    MaterialButton buttonC, buttonBrackOpen, buttonBrackClose;
    MaterialButton buttonDivide, buttonMultiply, buttonPlus, buttonMinus, buttonEquals;
    MaterialButton button0, button1, button2, button3, button4, button5, button6, button7, button8, button9;
    MaterialButton buttonAC, buttonDot;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        resultTv = findViewById(R.id.result_tv);
        solutionTv = findViewById(R.id.solution_tv);


        buttonC = findViewById(R.id.button_c);
        buttonC.setOnClickListener(this);

        assignId(R.id.button_ac);
        assignId(R.id.button_open_bracket);
        assignId(R.id.button_close_bracket);
        assignId(R.id.button_divide);
        assignId(R.id.button_multiply);
        assignId(R.id.button_minus);
        assignId(R.id.button_plus);
        assignId(R.id.button_dot);
        assignId(R.id.button_equals);
        assignId(R.id.button_7);
        assignId(R.id.button_6);
        assignId(R.id.button_8);
        assignId(R.id.button_9);
        assignId(R.id.button_5);
        assignId(R.id.button_4);
        assignId(R.id.button_3);
        assignId(R.id.button_2);
        assignId(R.id.button_1);
        assignId(R.id.button_0);


    }
    void assignId(int id) {
        MaterialButton btn = findViewById(id);
        btn.setOnClickListener(this);
        if(id== R.id.button_open_bracket){
            buttonBrackOpen=btn;
        }else if(id == R.id.button_close_bracket){
            buttonBrackClose=btn;
        }

    }



    Stack<Integer> stack = new Stack<>();

    @Override
    public void onClick(View view) {
        MaterialButton button = (MaterialButton) view;
        String buttonText = button.getText().toString();
        String dataToCalculate = solutionTv.getText().toString();

        if (buttonText.equals("(")) {
            if (!dataToCalculate.isEmpty() && !getLastChar(dataToCalculate).equals("(") && !isOperator(getLastChar(dataToCalculate))) {
                // Add an implied multiplication before the opening parenthesis
                dataToCalculate += "*";
            }
            // Push the index of the opening parenthesis onto the stack
            stack.push(dataToCalculate.length());
            dataToCalculate += buttonText;
        } else if (buttonText.equals(")")) {
            if (!stack.empty()) {
                // Get the index of the last opening parenthesis from the stack
                int openIndex = stack.pop();
                // Get the expression inside the parentheses
                String parenExpression = dataToCalculate.substring(openIndex + 1, dataToCalculate.length() - 1);
                // Evaluate the expression inside the parentheses
                String parenResult = getResult(parenExpression);
                // Replace the expression inside the parentheses with its result
                dataToCalculate = dataToCalculate.substring(0, openIndex) + parenResult;
            }
        } else {
            // Handle other buttons as before

            if (buttonText.equals("/")) {
                if (!isOperator(getLastChar(dataToCalculate))) {
                    // Add the division symbol to the expression
                    dataToCalculate += "/" + buttonText;
                }
            }

        }
            if (buttonText.equals("AC")) {
                solutionTv.setText("");
                resultTv.setText("0");
                return;
            }
            if (buttonText.equals("=")) {
                solutionTv.setText(resultTv.getText());
                return;
            }
            if (buttonText.equals("C")) {
                if (dataToCalculate.length() > 1) {
                    dataToCalculate = dataToCalculate.substring(0, dataToCalculate.length() - 1);
                } else {
                    dataToCalculate = "";
                }
            } else {
                if (isOperator(buttonText) && isOperator(getLastChar(dataToCalculate))) {
                    // Replace the last operator with the new one
                    dataToCalculate = dataToCalculate.substring(0, dataToCalculate.length() - 1) + buttonText;
                } else {
                    dataToCalculate += buttonText;
                }
            }
            solutionTv.setText(dataToCalculate);
            String finalResult = getResult(dataToCalculate);
            if (!finalResult.equals("Err")) {
                resultTv.setText(finalResult);
            }
        }


    private boolean isOperator (String s){
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("%") || s.equals(".");
    }
    private String getLastChar (String s){
        if (s.isEmpty()) {
            return "";
        } else {
            return s.substring(s.length() - 1);
        }
    }

    private String getResult(String data) {
        try {
            Context context = Context.enter();
            context.setOptimizationLevel(-1);
            Scriptable scriptable = context.initStandardObjects();
            // Replace all occurrences of "x" with "*" for multiplication
            data = data.replaceAll("x", "*");
            Object result = context.evaluateString(scriptable, data, "Javascript", 1, null);
            if (result == null || result == Undefined.instance) {
                return "Err";
            }
            String finalResult = Context.toString(Context.toObject(result, scriptable));
            if (finalResult.endsWith(".0")) {
                finalResult = finalResult.replace(".0", "");
            }
            return finalResult;
        } catch (Exception e) {
            return "Err";
        }
    }
}


