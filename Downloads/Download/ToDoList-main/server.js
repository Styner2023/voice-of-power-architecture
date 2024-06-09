const express = require('express');
const { exec } = require('child_process');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')));

app.post('/command', (req, res) => {
    const command = req.body.command;
    exec(`echo "${command}" | ./ToDoList`, (error, stdout, stderr) => {
        if (error) {
            return res.status(500).send(error.message);
        }
        res.send(stdout);
    });
});

app.listen(3000, () => {
    console.log('Server is running on http://localhost:3000');
});
