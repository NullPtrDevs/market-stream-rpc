window.BENCHMARK_DATA = {
  "lastUpdate": 1778760872729,
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
      },
      {
        "commit": {
          "author": {
            "email": "75732220+afiryulin@users.noreply.github.com",
            "name": "afiryulin",
            "username": "afiryulin"
          },
          "committer": {
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "0fd2ab623890f9c2469cfc6c0011f4adda4db981",
          "message": "Investigate dlt logger (#34)",
          "timestamp": "2026-05-13T15:11:07+03:00",
          "tree_id": "fb1dd12d84064b12a142265f23e92530cd3a9186",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/0fd2ab623890f9c2469cfc6c0011f4adda4db981"
        },
        "date": 1778674422985,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0219167549945967,
            "unit": "ns/iter",
            "extra": "iterations: 2742213937\ncpu: 1.0217418441338773 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1437.2233253717063,
            "unit": "ns/iter",
            "extra": "iterations: 1963167\ncpu: 1437.0579629751317 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6034.943745348307,
            "unit": "ns/iter",
            "extra": "iterations: 464886\ncpu: 6034.161757936355 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 194.85289215147537,
            "unit": "ns/iter",
            "extra": "iterations: 14374420\ncpu: 194.84112353750623 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 371.0791823914544,
            "unit": "ns/iter",
            "extra": "iterations: 7541702\ncpu: 371.04671491925853 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 723.2570909536187,
            "unit": "ns/iter",
            "extra": "iterations: 3870918\ncpu: 723.1915958953409 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1430.410345352994,
            "unit": "ns/iter",
            "extra": "iterations: 1962369\ncpu: 1430.2867676772307 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 2833.9364996633026,
            "unit": "ns/iter",
            "extra": "iterations: 991916\ncpu: 2833.642615906995 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6037.75633373209,
            "unit": "ns/iter",
            "extra": "iterations: 463905\ncpu: 6037.136344725748 ns\nthreads: 1"
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
            "value": 37270.361761697975,
            "unit": "ns/iter",
            "extra": "iterations: 119294\ncpu: 22840.763466729273 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 37511.02052332805,
            "unit": "ns/iter",
            "extra": "iterations: 119084\ncpu: 23165.52694736486 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 54708.29523354051,
            "unit": "ns/iter",
            "extra": "iterations: 62730\ncpu: 44730.54685158615 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 120021.52261535049,
            "unit": "ns/iter",
            "extra": "iterations: 26398\ncpu: 109835.30479581786 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 9.591934350170389,
            "unit": "ns/iter",
            "extra": "iterations: 283146386\ncpu: 9.590261279195689 ns\nthreads: 2"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "75732220+afiryulin@users.noreply.github.com",
            "name": "afiryulin",
            "username": "afiryulin"
          },
          "committer": {
            "email": "noreply@github.com",
            "name": "GitHub",
            "username": "web-flow"
          },
          "distinct": true,
          "id": "812b35c1ab1ea8ee7ea3699f630f398a7d1e8ee8",
          "message": "#37 Add UT for dlt_logger (#38)",
          "timestamp": "2026-05-13T17:38:22+03:00",
          "tree_id": "4262eacaeccd40d5bd18406a54f1fb08eaea3308",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/812b35c1ab1ea8ee7ea3699f630f398a7d1e8ee8"
        },
        "date": 1778683593376,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0234145994822146,
            "unit": "ns/iter",
            "extra": "iterations: 2741121156\ncpu: 1.0231838490104301 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1423.2056152180037,
            "unit": "ns/iter",
            "extra": "iterations: 1962987\ncpu: 1423.0466172216115 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6035.258592876767,
            "unit": "ns/iter",
            "extra": "iterations: 464309\ncpu: 6034.781361119429 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 194.54092037531652,
            "unit": "ns/iter",
            "extra": "iterations: 14375027\ncpu: 194.52198315870993 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 371.15968148215677,
            "unit": "ns/iter",
            "extra": "iterations: 7546830\ncpu: 371.1345175391522 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 723.6730119753183,
            "unit": "ns/iter",
            "extra": "iterations: 3872047\ncpu: 723.6188625809558 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1426.0429807135386,
            "unit": "ns/iter",
            "extra": "iterations: 1962671\ncpu: 1425.9516154261205 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 2831.3202960654007,
            "unit": "ns/iter",
            "extra": "iterations: 989241\ncpu: 2831.1629329961047 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6056.655154730091,
            "unit": "ns/iter",
            "extra": "iterations: 464098\ncpu: 6056.196947627439 ns\nthreads: 1"
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
            "value": 39021.4146496982,
            "unit": "ns/iter",
            "extra": "iterations: 114487\ncpu: 23734.079388926275 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 39524.43215959427,
            "unit": "ns/iter",
            "extra": "iterations: 116295\ncpu: 24202.595975751297 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 52155.50650402747,
            "unit": "ns/iter",
            "extra": "iterations: 66651\ncpu: 41939.79044575481 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 98492.32588971798,
            "unit": "ns/iter",
            "extra": "iterations: 31302\ncpu: 87796.93821481048 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 11.68270656065814,
            "unit": "ns/iter",
            "extra": "iterations: 241582644\ncpu: 11.681793730182033 ns\nthreads: 2"
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
          "id": "52ed1da31b78e36f1ca95393746813e97feba94a",
          "message": "Add implementation of config service base classes, (#35)",
          "timestamp": "2026-05-14T14:33:45+03:00",
          "tree_id": "7ed9c149a048a99691161888b75b1359559adcde",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/52ed1da31b78e36f1ca95393746813e97feba94a"
        },
        "date": 1778758565810,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 2.3276144462122117,
            "unit": "ns/iter",
            "extra": "iterations: 1203717994\ncpu: 2.3271575119446126 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 2431.0422949446256,
            "unit": "ns/iter",
            "extra": "iterations: 1031258\ncpu: 2430.837768046405 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 8406.153926079,
            "unit": "ns/iter",
            "extra": "iterations: 359952\ncpu: 8405.563238987419 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 364.3114893351752,
            "unit": "ns/iter",
            "extra": "iterations: 7250611\ncpu: 364.278580384467 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 573.2733393758626,
            "unit": "ns/iter",
            "extra": "iterations: 5184361\ncpu: 573.2234460524644 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 1142.5776390338237,
            "unit": "ns/iter",
            "extra": "iterations: 2284624\ncpu: 1142.4819287550154 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 2254.772833641515,
            "unit": "ns/iter",
            "extra": "iterations: 1225582\ncpu: 2254.647591103655 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 3512.3332758278,
            "unit": "ns/iter",
            "extra": "iterations: 805720\ncpu: 3512.0360907014815 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 14374.208822813905,
            "unit": "ns/iter",
            "extra": "iterations: 209661\ncpu: 14373.51112033235 ns\nthreads: 1"
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
            "value": 32315.7981522277,
            "unit": "ns/iter",
            "extra": "iterations: 168419\ncpu: 16705.076262179446 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 33883.01261423302,
            "unit": "ns/iter",
            "extra": "iterations: 156807\ncpu: 17842.638625826676 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 45782.57745368079,
            "unit": "ns/iter",
            "extra": "iterations: 82417\ncpu: 34332.90639067185 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 71958.85034426374,
            "unit": "ns/iter",
            "extra": "iterations: 42845\ncpu: 64153.257252888354 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 30.75368650685081,
            "unit": "ns/iter",
            "extra": "iterations: 80265550\ncpu: 30.749300366097287 ns\nthreads: 2"
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
          "id": "a166f751258e3baa3573ba2cb5361ff9d3980ecc",
          "message": "Separate one common_checks action into 2 action file. (#48)",
          "timestamp": "2026-05-14T15:12:11+03:00",
          "tree_id": "ee59bd1cd6874cea1e6c21aeaeffee0def0ef38b",
          "url": "https://github.com/NullPtrDevs/market-stream-rpc/commit/a166f751258e3baa3573ba2cb5361ff9d3980ecc"
        },
        "date": 1778760872470,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_Queue_push_pop",
            "value": 1.0648141448975654,
            "unit": "ns/iter",
            "extra": "iterations: 2615372775\ncpu: 1.064694376120054 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/1024",
            "value": 1609.0019561411982,
            "unit": "ns/iter",
            "extra": "iterations: 1726358\ncpu: 1608.6533946029733 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_LargeRange/4096",
            "value": 6795.400914793175,
            "unit": "ns/iter",
            "extra": "iterations: 412115\ncpu: 6794.749300559308 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/128",
            "value": 194.21469814555653,
            "unit": "ns/iter",
            "extra": "iterations: 14488821\ncpu: 194.19822841347826 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/256",
            "value": 382.491582621114,
            "unit": "ns/iter",
            "extra": "iterations: 7330251\ncpu: 382.44971065793004 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/512",
            "value": 807.0714403085777,
            "unit": "ns/iter",
            "extra": "iterations: 3468840\ncpu: 806.9940827481228 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/1024",
            "value": 1604.4210484795713,
            "unit": "ns/iter",
            "extra": "iterations: 1749314\ncpu: 1604.2328489910897 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/2048",
            "value": 3179.76398333392,
            "unit": "ns/iter",
            "extra": "iterations: 878671\ncpu: 3179.4315688124457 ns\nthreads: 1"
          },
          {
            "name": "BM_Queue_Complexity/4096",
            "value": 6794.97854881171,
            "unit": "ns/iter",
            "extra": "iterations: 412145\ncpu: 6794.47822489658 ns\nthreads: 1"
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
            "value": 33609.20886049434,
            "unit": "ns/iter",
            "extra": "iterations: 143220\ncpu: 19618.493813713194 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/512",
            "value": 34658.244145173616,
            "unit": "ns/iter",
            "extra": "iterations: 138262\ncpu: 20205.600316789863 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/4096",
            "value": 48257.99263686892,
            "unit": "ns/iter",
            "extra": "iterations: 71437\ncpu: 38746.69465403084 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue_Latency/10000",
            "value": 88720.8406064387,
            "unit": "ns/iter",
            "extra": "iterations: 36871\ncpu: 78906.26793414878 ns\nthreads: 1"
          },
          {
            "name": "BM_SPSC_Queue/threads:2",
            "value": 8.199249433590834,
            "unit": "ns/iter",
            "extra": "iterations: 343887492\ncpu: 8.197185883690134 ns\nthreads: 2"
          }
        ]
      }
    ]
  }
}