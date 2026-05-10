window.BENCHMARK_DATA = {
  "lastUpdate": 1778428704603,
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
      }
    ]
  }
}