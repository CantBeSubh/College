const url = 'https://twelve-data1.p.rapidapi.com/stocks?exchange=NASDAQ&format=json';

const options = {
    method: 'GET',
    headers: {
        'X-RapidAPI-Key': '450f2a756cmsh8fc8ee13e37a4f7p161605jsn96c659dcfc95',
        'X-RapidAPI-Host': 'twelve-data1.p.rapidapi.com'
    }
};
const getStockData = async () => {
    const response = await fetch(url, options);
    const data = await response.json();
    return data;
};

export default async function handler(req, res) {
    const { method } = req;
    if (method === 'GET') {
        try {
            const data = await getStockData();
            res.status(200).json(data);
        }
        catch (err) {
            res.status(500).json({ message: err.message });
        }
    }
}