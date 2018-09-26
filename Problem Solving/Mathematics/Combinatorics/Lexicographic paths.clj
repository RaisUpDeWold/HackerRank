(defn factorial
  ([n] (factorial n 1))
  ([n total]
    (if (= n 0)
      total
      (recur (dec n) (* n total)))))

(defn combination-with-repetition
  "Calculates (h+v)! / (h! * v!)"
  [h v]
  (/ (factorial (+ h v)) (* (factorial h) (factorial v))))

(def memoized-combination (memoize combination-with-repetition))

(defn find-next-step
  [h v k]
  (if (or (not= h 0) (not= v 0))
    (cond
      (= h 0)
      (do
        (print "V")
        (find-next-step h (dec v) k))
      (= v 0)
      (do
        (print "H")
        (find-next-step (dec h) v k))
      :else
      (do
        (if (> (memoized-combination (dec h) v) k)
          (do
            (print "H")
            (find-next-step (dec h) v k))
          (do
            (print "V")
            (find-next-step h (dec v) (- k (memoized-combination (dec h) v))))
          )))))

(defn execute-t-cases
  [t]
  (if (> t 0)
    (do
      (def args (str "[" (read-line) "]"))
      (apply find-next-step (read-string args))
      (print "\n")
      (recur (dec t)))))

(def t (Integer/parseInt (read-line)))
(execute-t-cases t)
