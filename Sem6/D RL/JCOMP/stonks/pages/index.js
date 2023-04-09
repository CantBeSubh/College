import Head from 'next/head'
import styles from '../styles/Home.module.css'
import cx from 'classnames';
import { useEffect, useState } from 'react';

export default function Home() {
  const [stockdata, setStockData] = useState(null);
  const [company, setCompany] = useState([]);
  const getData = async () => {
    const res = await fetch('/api/stockdata', { method: 'GET' });
    const data = await res.json();
    setStockData(data);
  }

  useEffect(() => {
    getData();
  }, []);

  return (
    <div className={styles.container}>
      <Head>
        <title>STONKS</title>
        <meta name="description" content="Generated by create next app" />
        <link rel="icon" href="/favicon.ico" />
      </Head>
      <div className={cx(styles["form-signin"], "text-center", "mt-5")}>

        <form
          onSubmit={(e) => {
            e.preventDefault();
            if (!stockdata) {
              alert("Please wait for the <stockdata> to load")
              return
            }
            const search = e.target[0].value;
            if (!search) {
              alert("Please enter a company's name");
              return
            }
            for (let i of stockdata.data) {
              if (i.name.toLowerCase().includes(search.toLowerCase())) {
                setCompany([i, ...company]);
              }
            }
            e.target.reset();
          }}
        >
          <h1 className="h1 mb-3 fw-normal text-light">STONKS</h1>

          <div className="form-floating mb-3">
            <textarea type="text" className="form-control" id="Input" placeholder="Enter Text" autoComplete='false' />
            <label htmlFor="Input">Enter Company's Name</label>
          </div>
          <button className={cx(styles["button"], "w-50", "btn", "btn-lg", "btn-outline-light")} type="submit">Submit</button>
          <div className='mt-3'>
            {/* {company.length > 0 && <h3 className="text-light">Your Stocks</h3>} */}

            {company &&
              company.map((i) => {
                return (
                  <div className="card text-white ml-3 mb-3 mt-10" key={i.symbol}>
                    <h4 className="card-header">{i.name}</h4>
                    <div className="card-body">
                      <h5 className="card-title">Stock Price: $ {Math.round(Math.random() * 100)}</h5>
                      <p className="card-text">Stock Symbol: {i.symbol}</p>
                      <p className="card-text">Stock Exchange: {i.exchange}</p>
                    </div>
                  </div>
                )
              }
              )
            }

          </div>

        </form>
      </div>
    </div>
  )
}