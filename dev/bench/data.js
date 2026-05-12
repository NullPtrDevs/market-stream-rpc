window.BENCHMARK_DATA = {
  "lastUpdate": 1778586454805,
  "repoUrl": "https://github.com/NullPtrDevs/market-stream-rpc",
  "entries": {
    "Benchmark": [
      {
        "commit": {
          "author": {
            "email": "ahillodessa@gmail.com",
            "name": "ahillodessa",
            "username": "ahillodessa"
          },
          "committer": {
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "0dd81c9b21bddf3ab0ad9d9ca8637763c7e4ba51",
          "message": "Add CI action for benchmark (#31)",
          "timestamp": "2026-05-10T18:56:31+03:00",
          "tree_id": "ff135d74f968a1da80d999924c783dcc698640b0",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/0dd81c9b21bddf3ab0ad9d9ca8637763c7e4ba51"
        },
        "date": 1778428704380,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0724805676848472,
            "unit": "ns/iter",
            "extra": "iterations: 2630088189\ncpu: 1.0722174179536608 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1609.215142553243,
            "unit": "ns/iter",
            "extra": "iterations: 1741701\ncpu: 1609.0130033800294 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6835.51041808274,
            "unit": "ns/iter",
            "extra": "iterations: 411976\ncpu: 6834.579067712686 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 193.83761117294986,
            "unit": "ns/iter",
            "extra": "iterations: 14529725\ncpu: 193.81539574905923 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 382.85174145141985,
            "unit": "ns/iter",
            "extra": "iterations: 7334916\ncpu: 382.7920057980212 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 807.7571739902188,
            "unit": "ns/iter",
            "extra": "iterations: 3469896\ncpu: 807.6452504628384 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1603.3620998253152,
            "unit": "ns/iter",
            "extra": "iterations: 1747612\ncpu: 1603.220630780746 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 3169.961965693898,
            "unit": "ns/iter",
            "extra": "iterations: 875762\ncpu: 3169.656600765959 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6789.320969513628,
            "unit": "ns/iter",
            "extra": "iterations: 412413\ncpu: 6788.453157393183 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_BigO",
            "unit": "ns/iter",
            "extra": "iterations: undefined\ncpu: undefined ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_RMS",
            "unit": "undefined/iter",
            "extra": "iterations: undefined\ncpu: undefined undefined\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/100",
            "value": 33631.852726728626,
            "unit": "ns/iter",
            "extra": "iterations: 143597\ncpu: 19469.756492127297 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 34537.80843597817,
            "unit": "ns/iter",
            "extra": "iterations: 139640\ncpu: 20244.044457175565 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 49020.12256000371,
            "unit": "ns/iter",
            "extra": "iterations: 70953\ncpu: 39360.45604837001 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 89424.30257840459,
            "unit": "ns/iter",
            "extra": "iterations: 35138\ncpu: 79353.55717456873 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 7.967851978139822,
            "unit": "ns/iter",
            "extra": "iterations: 352078428\ncpu: 7.967248913642612 ns\nthreads: 2"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "ahillodessa@gmail.com",
            "name": "ahillodessa",
            "username": "ahillodessa"
          },
          "committer": {
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "7e1e97b6457fc3fb6eeedeafd6e6a879d4726378",
          "message": "Update issue templates",
          "timestamp": "2026-05-12T08:04:57+03:00",
          "tree_id": "7a625d8295ea45bc8d999c9022d53b496ba6c9ce",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/7e1e97b6457fc3fb6eeedeafd6e6a879d4726378"
        },
        "date": 1778562410832,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0218991277538616,
            "unit": "ns/iter",
            "extra": "iterations: 2734968245\ncpu: 1.0218367826058616 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1428.2561003283506,
            "unit": "ns/iter",
            "extra": "iterations: 1961001\ncpu: 1428.1557995125959 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6096.658222848601,
            "unit": "ns/iter",
            "extra": "iterations: 463337\ncpu: 6096.295661689011 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 194.74489487220941,
            "unit": "ns/iter",
            "extra": "iterations: 14382353\ncpu: 194.73652962070952 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 371.5702285909146,
            "unit": "ns/iter",
            "extra": "iterations: 7534289\ncpu: 371.553276891821 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 724.4956478345321,
            "unit": "ns/iter",
            "extra": "iterations: 3871521\ncpu: 724.4327759038372 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1428.0939737280144,
            "unit": "ns/iter",
            "extra": "iterations: 1962623\ncpu: 1428.0222656108695 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 2852.572775376175,
            "unit": "ns/iter",
            "extra": "iterations: 991235\ncpu: 2852.4471391748657 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6032.179434205591,
            "unit": "ns/iter",
            "extra": "iterations: 463702\ncpu: 6031.702000422687 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_BigO",
            "value": null,
            "unit": "ns/iter",
            "extra": "iterations: undefined\ncpu: undefined ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_RMS",
            "unit": "undefined/iter",
            "extra": "iterations: undefined\ncpu: undefined undefined\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/100",
            "value": 38648.93307079952,
            "unit": "ns/iter",
            "extra": "iterations: 118334\ncpu: 23406.34231074751 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 38782.663990422385,
            "unit": "ns/iter",
            "extra": "iterations: 119446\ncpu: 23507.746320513033 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 53870.398525955694,
            "unit": "ns/iter",
            "extra": "iterations: 65534\ncpu: 43829.365657521266 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 106351.02699513237,
            "unit": "ns/iter",
            "extra": "iterations: 27116\ncpu: 96131.22628706311 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 11.149398698029968,
            "unit": "ns/iter",
            "extra": "iterations: 250749220\ncpu: 11.148768119797133 ns\nthreads: 2"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "ahillodessa@gmail.com",
            "name": "ahillodessa",
            "username": "ahillodessa"
          },
          "committer": {
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "42cab0c66067e04b9c517ea8d6332a88c042e3e0",
          "message": "Add codestyle support for clang-tidy (#33)",
          "timestamp": "2026-05-12T14:45:29+03:00",
          "tree_id": "8acb2b465d1f4f0dce641ed72044893a68641de8",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/42cab0c66067e04b9c517ea8d6332a88c042e3e0"
        },
        "date": 1778586454447,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0294396403447923,
            "unit": "ns/iter",
            "extra": "iterations: 2732993544\ncpu: 1.0293482745965827 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1426.6156135251006,
            "unit": "ns/iter",
            "extra": "iterations: 1960800\ncpu: 1426.5167707058347 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6144.964315227602,
            "unit": "ns/iter",
            "extra": "iterations: 464680\ncpu: 6144.275376603252 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 194.27707526000071,
            "unit": "ns/iter",
            "extra": "iterations: 14353057\ncpu: 194.2634445052368 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 373.04830470171976,
            "unit": "ns/iter",
            "extra": "iterations: 7493991\ncpu: 373.0237319473696 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 723.9078423070741,
            "unit": "ns/iter",
            "extra": "iterations: 3871093\ncpu: 723.8565133929873 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1429.1963451028528,
            "unit": "ns/iter",
            "extra": "iterations: 1964597\ncpu: 1429.058237389144 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 2825.399255188219,
            "unit": "ns/iter",
            "extra": "iterations: 991123\ncpu: 2825.2079671241618 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6046.079626523788,
            "unit": "ns/iter",
            "extra": "iterations: 462145\ncpu: 6045.542269201226 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_BigO",
            "value": null,
            "unit": "ns/iter",
            "extra": "iterations: undefined\ncpu: undefined ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity_RMS",
            "unit": "undefined/iter",
            "extra": "iterations: undefined\ncpu: undefined undefined\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/100",
            "value": 38461.40248125732,
            "unit": "ns/iter",
            "extra": "iterations: 117521\ncpu: 23403.854825945982 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 38825.82866137565,
            "unit": "ns/iter",
            "extra": "iterations: 116261\ncpu: 23697.938715476423 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 56979.37093696727,
            "unit": "ns/iter",
            "extra": "iterations: 59746\ncpu: 46749.10663475382 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 122757.76085566194,
            "unit": "ns/iter",
            "extra": "iterations: 25010\ncpu: 112389.76089564172 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 10.723802883654187,
            "unit": "ns/iter",
            "extra": "iterations: 265908866\ncpu: 10.720603110691311 ns\nthreads: 2"
          }
        ]
      }
    ]
  }
}