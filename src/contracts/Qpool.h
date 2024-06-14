using namespace QPI;

#define QPOOL_INITIAL_QPT 1000
#define QPOOL_MAX_NUMBER_OF_POOL 65536
#define QPOOL_FEE_CREATE_POOL 100000000LL
#define QPOOL_FEE_ISSUE_ASSET 1000000000LL
#define QPOOL_TOKEN_TRANSER_FEE 1000LL // Amount of qus
#define QPOOL_ENABLE_TOKEN_FEE 100000000LL
#define QPOOL_MULTIPRECISION_FEE_UNIT 1
#define QPOOL_MAX_TOKEN 65536
#define QPOOL_QWALLET_TOKEN 23720092042876753ULL
#define QPOOL_CONTRACTID _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 7)
#define QPOOL_ISSUER_QWALLET _mm256_set_epi8(159, 170, 86, 88, 138, 163, 10, 22, 193, 210, 63, 118, 200, 26, 123, 233, 100, 223, 40, 231, 166, 64, 98, 26, 117, 108, 211, 34, 206, 186, 192, 98);

struct QPOOL2
{
};

struct QPOOL
{
public:
	struct BIGNumberToString_input {
		sint64 a;
	};

	struct BIGNumberToString_output {
		uint8 len;
		uint8_128 result;
	};

	struct BIGStringToNumber_input {
		uint8 len;
		uint8_128 a;
	};

	struct BIGStringToNumber_output {
		sint64 result;
	};

	struct BIGPlus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGPlus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BIGMinus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGMinus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BIGMultiple_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGMultiple_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BIGDiv_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGDiv_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BIGModulus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGModulus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BIGBigOrEqualComparison_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGBigOrEqualComparison_output {
		bit result;
	};

	struct BIGSmallOrEqualComparison_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGSmallOrEqualComparison_output {
		bit result;
	};

	struct BIGBigComparison_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGBigComparison_output {
		bit result;
	};
	struct BIGSmallComparison_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};

	struct BIGSmallComparison_output {
		bit result;
	};

	struct CreateLiquidityPool_input
	{
		uint64 NameOfLPToken; // Name of LP token
		uint64 swapFee;		  // Swap fee in a Pool

		uint64 initialAmountOfQWALLET;
		uint64 initialAmountOfQU;
		uint64 initialAmount1;
		uint64 initialAmount2;
		uint64 initialAmount3;
		uint64 initialAmount4;

		uint16 IndexOfToken1;
		uint16 IndexOfToken2;
		uint16 IndexOfToken3;
		uint16 IndexOfToken4;

		uint8 NumberOfToken; // Number(maximum 5) of token in a pool

		uint8 WeightOfQWALLET;
		uint8 Weight1;
		uint8 Weight2;
		uint8 Weight3;
		uint8 Weight4;
	};
	struct CreateLiquidityPool_output
	{
		uint64 poolAddress; // created pool address
	};

	struct PoolList_input
	{
		uint32 NumberOfPool;
	};

	struct PoolList_output
	{
		uint64 NameOfLPToken; // Name of LP token
		uint64 swapFee;		  // Swap fee in a Pool

		uint64 liquidityOfQWALLET;
		uint64 liquidityOfQU;
		uint64 liquidity1;
		uint64 liquidity2;
		uint64 liquidity3;
		uint64 liquidity4;
		uint64 totalAmountOfQPT;
		uint64 totalSupplyByQU;

		uint16 IndexOfToken1;
		uint16 IndexOfToken2;
		uint16 IndexOfToken3;
		uint16 IndexOfToken4;

		uint8 NumberOfToken; // Number(maximum 5) of token in a pool

		uint8 WeightOfQWALLET;
		uint8 Weight1;
		uint8 Weight2;
		uint8 Weight3;
		uint8 Weight4;
	};

	struct IssueAsset_input
	{
		uint64 assetName;
		sint64 numberOfShares;
		uint64 unitOfMeasurement;
		sint8 numberOfDecimalPlaces;
	};

	struct IssueAsset_output
	{
		sint64 issuedNumberOfShares;
	};

	struct EnableToken_input
	{
		uint64 assetName;
		id issuer;
	};

	struct EnableToken_output
	{
		uint16 TokenID;
	};

	struct GetNumberOfEnableToken_input
	{
	};

	struct GetNumberOfEnableToken_output
	{
		uint16 NumberOfEnableToken;
	};

	struct GetEnableToken_input
	{
		uint32 NumberOfToken;
	};

	struct GetEnableToken_output
	{
		uint64 assetName;
		id issuer;
	};

	struct Swap_input {
		uint64 AmountOfToken1;

		uint16 IndexOfToken1;
		uint16 IndexOfToken2;

		uint16 Poolnum;
	};

	struct Swap_output {
		uint64 AmountOfToken2;
	};

	struct GetValueOfToken_input {
		uint16 IndexOfToken;
		uint16 Poolnum;
	};

	struct GetValueOfToken_output {
		uint64 ValueOfToken;
	};

	struct GetBIGStatus_input {

	};

	struct GetBIGStatus_output {
		sint64 BIGTest;
		uint8 BIGStringNumberLen;
		uint8_128 BIGStringNumber;
		bit BIGTestComparisonResult;
	};

private:
	uint32 _NumberOfPool;		
	uint16 _NumberOfEnableToken;	   // Number of Pool
	struct _PoolInfo
	{
		uint64 NameOfLPToken; // Name of LP token
		uint64 swapFee;		  // Swap fee in a Pool

		uint64 liquidityOfQWALLET;
		uint64 liquidityOfQU;
		uint64 liquidity1;
		uint64 liquidity2;
		uint64 liquidity3;
		uint64 liquidity4;
		uint64 TotalAmountOfQPT;
		uint64 totalSupply;

		uint16 IndexOfToken1;
		uint16 IndexOfToken2;
		uint16 IndexOfToken3;
		uint16 IndexOfToken4;

		uint8 NumberOfToken; // Number(maximum 5) of token in a pool

		uint8 Weight1;
		uint8 Weight2;
		uint8 Weight3;
		uint8 Weight4;

		uint8 WeightOfQWALLET;
	};
	array<_PoolInfo, QPOOL_MAX_NUMBER_OF_POOL> _pools;
	sint64 BIGTest;
	uint8_128 BIGStringNumber;
	uint8 BIGStringNumberLen;
	uint64_16777216 _QPTAmountOfUser; // Amount of LP token of nth user in Qpool
	id_16777216 _UserID;	   // The id of nth user in Qpool
	uint16_16777216 _PoolNumberOfUser;     // The number of pool user provided
	uint32 _NumberOfTotalUser;
	bit BIGTestComparisonResult;

	struct _tokenInfor
	{
		uint64 assetName;
		id issuer;
	};

	array<_tokenInfor, QPOOL_MAX_TOKEN> _TokenList;

	PUBLIC_PROCEDURE(EnableToken)
		if (qpi.invocationReward() < QPOOL_ENABLE_TOKEN_FEE)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		_tokenInfor newToken;
		newToken.assetName = input.assetName;
		newToken.issuer = input.issuer;
		state._TokenList.set(state._NumberOfEnableToken, newToken);
		output.TokenID = state._NumberOfEnableToken;
		state._NumberOfEnableToken++;
	_

	PUBLIC_FUNCTION(GetNumberOfEnableToken)
		output.NumberOfEnableToken = state._NumberOfEnableToken;
	_

	PUBLIC_FUNCTION(GetEnableToken) 
		if (input.NumberOfToken >= state._NumberOfEnableToken) return;
		_tokenInfor token = state._TokenList.get(input.NumberOfToken);
		output.assetName = token.assetName;
		output.issuer = token.issuer;
	_

	PUBLIC_FUNCTION(GetValueOfToken)
		_PoolInfo pool = state._pools.get(input.Poolnum);
		_tokenInfor token = state._TokenList.get(input.IndexOfToken);

		uint64 liquidityOfToken;
		uint8 weightOfToken;

		if(input.IndexOfToken == pool.IndexOfToken1) {liquidityOfToken = pool.liquidity1; weightOfToken = pool.Weight1; }
		if(input.IndexOfToken == pool.IndexOfToken2) {liquidityOfToken = pool.liquidity2; weightOfToken = pool.Weight2; }
		if(input.IndexOfToken == pool.IndexOfToken3) {liquidityOfToken = pool.liquidity3; weightOfToken = pool.Weight3; }
		if(input.IndexOfToken == pool.IndexOfToken4) {liquidityOfToken = pool.liquidity4; weightOfToken = pool.Weight4; }

		uint8 weightOfQu = 100 - pool.WeightOfQWALLET;
		if(pool.NumberOfToken > 2) weightOfQu -= pool.Weight1;
		if(pool.NumberOfToken > 3) weightOfQu -= pool.Weight2;
		if(pool.NumberOfToken > 4) weightOfQu -= pool.Weight3;
		if(pool.NumberOfToken > 5) weightOfQu -= pool.Weight4;

		output.ValueOfToken = pool.liquidityOfQU * weightOfToken / liquidityOfToken / weightOfQu;   // Amount of qu per 1 token in current pool
	_

	PUBLIC_PROCEDURE(CreateLiquidityPool) 
		if (qpi.invocationReward() < QPOOL_FEE_CREATE_POOL + QPOOL_TOKEN_TRANSER_FEE * (input.NumberOfToken - 1) + input.initialAmountOfQU)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		if (input.NumberOfToken > 6)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		uint8 QuWeight = 100 - input.WeightOfQWALLET;
		if(input.NumberOfToken > 2) QuWeight -= input.Weight1;
		if(input.NumberOfToken > 3) QuWeight -= input.Weight2;
		if(input.NumberOfToken > 4) QuWeight -= input.Weight3;
		if(input.NumberOfToken > 5) QuWeight -= input.Weight4;

		if (input.WeightOfQWALLET < 10 || QuWeight < 20)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint64 assetnameOftoken1 = state._TokenList.get(input.IndexOfToken1).assetName;
		uint64 assetnameOftoken2 = state._TokenList.get(input.IndexOfToken2).assetName;
		uint64 assetnameOftoken3 = state._TokenList.get(input.IndexOfToken3).assetName;
		uint64 assetnameOftoken4 = state._TokenList.get(input.IndexOfToken4).assetName;

		id issuerOfToken1 = state._TokenList.get(input.IndexOfToken1).issuer;
		id issuerOfToken2 = state._TokenList.get(input.IndexOfToken2).issuer;
		id issuerOfToken3 = state._TokenList.get(input.IndexOfToken3).issuer;
		id issuerOfToken4 = state._TokenList.get(input.IndexOfToken4).issuer;

		id IssuerQWALLET = _mm256_set_epi8(
			159, 170, 86, 88, 138, 163, 10, 22, 193, 210, 63, 118, 200, 26, 123, 233,
			100, 223, 40, 231, 166, 64, 98, 26, 117, 108, 211, 34, 206, 186, 192, 98);

		if (input.NumberOfToken > 2 && qpi.numberOfPossessedShares(assetnameOftoken1, issuerOfToken1, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.initialAmount1)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		if (input.NumberOfToken > 3 && qpi.numberOfPossessedShares(assetnameOftoken2, issuerOfToken2, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.initialAmount2)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		if (input.NumberOfToken > 4 && qpi.numberOfPossessedShares(assetnameOftoken3, issuerOfToken3, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.initialAmount3)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		if (input.NumberOfToken > 5 && qpi.numberOfPossessedShares(assetnameOftoken4, issuerOfToken4, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.initialAmount4)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		if (qpi.numberOfPossessedShares(QPOOL_QWALLET_TOKEN, IssuerQWALLET, qpi.invocator(), qpi.invocator(), 6, 6) < input.initialAmountOfQWALLET)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if (input.NumberOfToken > 2)
			qpi.transferShareOwnershipAndPossession(assetnameOftoken1, issuerOfToken1, qpi.invocator(), qpi.invocator(), input.initialAmount1, QPOOL_CONTRACTID);
		if (input.NumberOfToken > 3)
			qpi.transferShareOwnershipAndPossession(assetnameOftoken2, issuerOfToken2, qpi.invocator(), qpi.invocator(), input.initialAmount2, QPOOL_CONTRACTID);
		if (input.NumberOfToken > 4)
			qpi.transferShareOwnershipAndPossession(assetnameOftoken3, issuerOfToken3, qpi.invocator(), qpi.invocator(), input.initialAmount3, QPOOL_CONTRACTID);
		if (input.NumberOfToken > 5)
			qpi.transferShareOwnershipAndPossession(assetnameOftoken4, issuerOfToken4, qpi.invocator(), qpi.invocator(), input.initialAmount4, QPOOL_CONTRACTID);
		qpi.transferShareOwnershipAndPossession(QPOOL_QWALLET_TOKEN, IssuerQWALLET, qpi.invocator(), qpi.invocator(), input.initialAmountOfQWALLET, QPOOL_CONTRACTID);

		if (qpi.invocationReward() > QPOOL_FEE_CREATE_POOL + QPOOL_TOKEN_TRANSER_FEE * (input.NumberOfToken - 1) + input.initialAmountOfQU)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - (QPOOL_FEE_CREATE_POOL + QPOOL_TOKEN_TRANSER_FEE * (input.NumberOfToken - 1) + input.initialAmountOfQU));
		}
		_PoolInfo newPool;
		newPool.NameOfLPToken = input.NameOfLPToken;
		newPool.NumberOfToken = input.NumberOfToken;
		newPool.swapFee = input.swapFee;

		newPool.liquidityOfQWALLET = input.initialAmountOfQWALLET;
		newPool.liquidityOfQU = input.initialAmountOfQU;
		newPool.liquidity1 = input.initialAmount1;
		newPool.liquidity2 = input.initialAmount2;
		newPool.liquidity3 = input.initialAmount3;
		newPool.liquidity4 = input.initialAmount4;

		newPool.IndexOfToken1 = input.IndexOfToken1;
		newPool.IndexOfToken2 = input.IndexOfToken2;
		newPool.IndexOfToken3 = input.IndexOfToken3;
		newPool.IndexOfToken4 = input.IndexOfToken4;

		newPool.Weight1 = input.Weight1;
		newPool.Weight2 = input.Weight2;
		newPool.Weight3 = input.Weight3;
		newPool.Weight4 = input.Weight4;
		newPool.WeightOfQWALLET = input.WeightOfQWALLET;

		newPool.TotalAmountOfQPT = QPOOL_INITIAL_QPT;
		newPool.totalSupply = (uint64)100 * input.initialAmountOfQU / QuWeight;

		state._pools.set(state._NumberOfPool, newPool);

		state._QPTAmountOfUser.set(state._NumberOfTotalUser, QPOOL_INITIAL_QPT);
		state._UserID.set(state._NumberOfTotalUser, qpi.invocator());
		state._PoolNumberOfUser.set(state._NumberOfTotalUser, state._NumberOfPool);
		state._NumberOfPool++;
		state._NumberOfTotalUser++;
	_

	PUBLIC_PROCEDURE(IssueAsset) 
		if (qpi.invocationReward() < QPOOL_FEE_ISSUE_ASSET)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}

			output.issuedNumberOfShares = 0;
			return;
		}
		if (qpi.invocationReward() > QPOOL_FEE_ISSUE_ASSET)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - QPOOL_FEE_ISSUE_ASSET);
		}

		output.issuedNumberOfShares = qpi.issueAsset(input.assetName, qpi.invocator(), input.numberOfDecimalPlaces, input.numberOfShares, input.unitOfMeasurement);
	_

	PUBLIC_FUNCTION(PoolList) 
		if (input.NumberOfPool >= state._NumberOfPool) return;
		_PoolInfo pool;
		pool = state._pools.get(input.NumberOfPool);

		output.NameOfLPToken = pool.NameOfLPToken;
		output.swapFee = pool.swapFee;

		output.liquidityOfQWALLET = pool.liquidityOfQWALLET;
		output.liquidityOfQU = pool.liquidityOfQU;
		output.liquidity1 = pool.liquidity1;
		output.liquidity2 = pool.liquidity2;
		output.liquidity3 = pool.liquidity3;
		output.liquidity4 = pool.liquidity4;

		output.IndexOfToken1 = pool.IndexOfToken1;
		output.IndexOfToken2 = pool.IndexOfToken2;
		output.IndexOfToken3 = pool.IndexOfToken3;
		output.IndexOfToken4 = pool.IndexOfToken4;

		output.NumberOfToken = pool.NumberOfToken; // Number(maximum 5) of token in a pool

		output.Weight1 = pool.Weight1;
		output.Weight2 = pool.Weight2;
		output.Weight3 = pool.Weight3;
		output.Weight4 = pool.Weight4;
		output.WeightOfQWALLET = pool.WeightOfQWALLET;

		output.totalAmountOfQPT = pool.TotalAmountOfQPT;
		output.totalSupplyByQU = pool.totalSupply;
	_

	PUBLIC_PROCEDURE(Swap) 
		if(input.Poolnum >= state._NumberOfPool || input.IndexOfToken1 >= state._NumberOfEnableToken || input.IndexOfToken2 >= state._NumberOfEnableToken) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		_PoolInfo pool = state._pools.get(input.Poolnum);
		_tokenInfor token1 = state._TokenList.get(input.IndexOfToken1);
		_tokenInfor token2 = state._TokenList.get(input.IndexOfToken2);

		if (qpi.numberOfPossessedShares(token1.assetName, token1.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.AmountOfToken1)
		{
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint64 ValueOfToken1ByQu;
		uint64 ValueOfToken2ByQu;
		uint64 liquidityOfToken1;
		uint64 liquidityOfToken2;
		uint8 weightOfToken1;
		uint8 weightOfToken2;

		uint8 weightOfQu = 100 - pool.WeightOfQWALLET;
		if(pool.NumberOfToken > 2) weightOfQu -= pool.Weight1;
		if(pool.NumberOfToken > 3) weightOfQu -= pool.Weight2;
		if(pool.NumberOfToken > 4) weightOfQu -= pool.Weight3;
		if(pool.NumberOfToken > 5) weightOfQu -= pool.Weight4;

		if(input.IndexOfToken1 == pool.IndexOfToken1) {liquidityOfToken1 = pool.liquidity1; weightOfToken1 = pool.Weight1; }
		if(input.IndexOfToken1 == pool.IndexOfToken2) {liquidityOfToken1 = pool.liquidity2; weightOfToken1 = pool.Weight2; }
		if(input.IndexOfToken1 == pool.IndexOfToken3) {liquidityOfToken1 = pool.liquidity3; weightOfToken1 = pool.Weight3; }
		if(input.IndexOfToken1 == pool.IndexOfToken4) {liquidityOfToken1 = pool.liquidity4; weightOfToken1 = pool.Weight4; }

		if(input.IndexOfToken2 == pool.IndexOfToken1) {liquidityOfToken2 = pool.liquidity1; weightOfToken2 = pool.Weight1; }
		if(input.IndexOfToken2 == pool.IndexOfToken2) {liquidityOfToken2 = pool.liquidity2; weightOfToken2 = pool.Weight2; }
		if(input.IndexOfToken2 == pool.IndexOfToken3) {liquidityOfToken2 = pool.liquidity3; weightOfToken2 = pool.Weight3; }
		if(input.IndexOfToken2 == pool.IndexOfToken4) {liquidityOfToken2 = pool.liquidity4; weightOfToken2 = pool.Weight4; }

		// Begin to calculate the BIG numbers
		// 
		// ValueOfToken1ByQu = pool.liquidityOfQU * weightOfToken1 / liquidityOfToken1 / weightOfQu;   // Amount of qu per 1 token1 in current pool
		// ValueOfToken2ByQu = pool.liquidityOfQU * weightOfToken2 / liquidityOfToken2 / weightOfQu;	// Amount of qu per 1 token2 in current pool
		//

		BIGNumberToString_input BigliquidityOfQUInput;
		BIGNumberToString_output BigliquidityOfQUOutput;
		BigliquidityOfQUInput.a = pool.liquidityOfQU;
		
		CALL(BIGNumberToString, BigliquidityOfQUInput, BigliquidityOfQUOutput);

		BIGNumberToString_input BigweightOfToken1Input;
		BIGNumberToString_output BigweightOfToken1Output;
		BigweightOfToken1Input.a = weightOfToken1;
		
		CALL(BIGNumberToString, BigweightOfToken1Input, BigweightOfToken1Output);

		BIGNumberToString_input BigweightOfToken2Input;
		BIGNumberToString_output BigweightOfToken2Output;
		BigweightOfToken2Input.a = weightOfToken2;
		
		CALL(BIGNumberToString, BigweightOfToken2Input, BigweightOfToken2Output);

		BIGNumberToString_input BigliquidityOfToken1Input;
		BIGNumberToString_output BigliquidityOfToken1Output;
		BigliquidityOfToken1Input.a = liquidityOfToken1;
		
		CALL(BIGNumberToString, BigliquidityOfToken1Input, BigliquidityOfToken1Output);

		BIGNumberToString_input BigliquidityOfToken2Input;
		BIGNumberToString_output BigliquidityOfToken2Output;
		BigliquidityOfToken2Input.a = liquidityOfToken2;
		
		CALL(BIGNumberToString, BigliquidityOfToken2Input, BigliquidityOfToken2Output);

		BIGNumberToString_input BigweightOfQuInput;
		BIGNumberToString_output BigweightOfQuOutput;
		BigweightOfQuInput.a = weightOfQu;
		
		CALL(BIGNumberToString, BigweightOfQuInput, BigweightOfQuOutput);

		BIGMultiple_input liquidityOfQUMultipleWeightOfToken1_input;
		BIGMultiple_output liquidityOfQUMultipleWeightOfToken1_output;

		for(uint8 i = 0 ; i < BigliquidityOfQUOutput.len; i++) liquidityOfQUMultipleWeightOfToken1_input.a.set(i, BigliquidityOfQUOutput.result.get(i));
		liquidityOfQUMultipleWeightOfToken1_input.alen = BigliquidityOfQUOutput.len;
		for(uint8 i = 0 ; i < BigweightOfToken1Output.len; i++) liquidityOfQUMultipleWeightOfToken1_input.b.set(i, BigweightOfToken1Output.result.get(i));
		liquidityOfQUMultipleWeightOfToken1_input.blen = BigweightOfToken1Output.len;

		CALL(BIGMultiple, liquidityOfQUMultipleWeightOfToken1_input, liquidityOfQUMultipleWeightOfToken1_output);

		BIGDiv_input liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input;
		BIGDiv_output liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_output;

		for(uint8 i = 0 ; i < liquidityOfQUMultipleWeightOfToken1_output.resultlen; i++) liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input.a.set(i, liquidityOfQUMultipleWeightOfToken1_output.result.get(i));
		liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input.alen = liquidityOfQUMultipleWeightOfToken1_output.resultlen;
		for(uint8 i = 0 ; i < BigliquidityOfToken1Output.len; i++) liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input.b.set(i, BigliquidityOfToken1Output.result.get(i));
		liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input.blen = BigliquidityOfToken1Output.len;

		CALL(BIGDiv, liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_input, liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_output);
		
		BIGDiv_input ValueOfToken1ByQu_input;
		BIGDiv_output ValueOfToken1ByQu_output;

		for(uint8 i = 0 ; i < liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_output.resultlen; i++) ValueOfToken1ByQu_input.a.set(i, liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_output.result.get(i));
		ValueOfToken1ByQu_input.alen = liquidityOfQUMultipleWeightOfToken1DivideliquidityOfToken1_output.resultlen;
		for(uint8 i = 0 ; i < BigweightOfQuOutput.len; i++) ValueOfToken1ByQu_input.b.set(i, BigweightOfQuOutput.result.get(i));
		ValueOfToken1ByQu_input.blen = BigweightOfQuOutput.len;

		CALL(BIGDiv, ValueOfToken1ByQu_input, ValueOfToken1ByQu_output);


		BIGMultiple_input liquidityOfQUMultipleWeightOfToken2_input;
		BIGMultiple_output liquidityOfQUMultipleWeightOfToken2_output;

		for(uint8 i = 0 ; i < BigliquidityOfQUOutput.len; i++) liquidityOfQUMultipleWeightOfToken2_input.a.set(i, BigliquidityOfQUOutput.result.get(i));
		liquidityOfQUMultipleWeightOfToken2_input.alen = BigliquidityOfQUOutput.len;
		for(uint8 i = 0 ; i < BigweightOfToken2Output.len; i++) liquidityOfQUMultipleWeightOfToken2_input.b.set(i, BigweightOfToken2Output.result.get(i));
		liquidityOfQUMultipleWeightOfToken2_input.blen = BigweightOfToken2Output.len;

		CALL(BIGMultiple, liquidityOfQUMultipleWeightOfToken2_input, liquidityOfQUMultipleWeightOfToken2_output);

		BIGDiv_input liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input;
		BIGDiv_output liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_output;

		for(uint8 i = 0 ; i < liquidityOfQUMultipleWeightOfToken2_output.resultlen; i++) liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input.a.set(i, liquidityOfQUMultipleWeightOfToken2_output.result.get(i));
		liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input.alen = liquidityOfQUMultipleWeightOfToken2_output.resultlen;
		for(uint8 i = 0 ; i < BigliquidityOfToken2Output.len; i++) liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input.b.set(i, BigliquidityOfToken2Output.result.get(i));
		liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input.blen = BigliquidityOfToken2Output.len;

		CALL(BIGDiv, liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_input, liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_output);
		
		BIGDiv_input ValueOfToken2ByQu_input;
		BIGDiv_output ValueOfToken2ByQu_output;

		for(uint8 i = 0 ; i < liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_output.resultlen; i++) ValueOfToken2ByQu_input.a.set(i, liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_output.result.get(i));
		ValueOfToken2ByQu_input.alen = liquidityOfQUMultipleWeightOfToken2DivideliquidityOfToken2_output.resultlen;
		for(uint8 i = 0 ; i < BigweightOfQuOutput.len; i++) ValueOfToken2ByQu_input.b.set(i, BigweightOfQuOutput.result.get(i));
		ValueOfToken2ByQu_input.blen = BigweightOfQuOutput.len;

		CALL(BIGDiv, ValueOfToken2ByQu_input, ValueOfToken2ByQu_output);

		// 
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




		// The type of ValueOfToken1ByQu, ValueOfToken2ByQu to Number
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		BIGStringToNumber_input NumberValueOfToken1ByQu_input;
		BIGStringToNumber_output NumberValueOfToken1ByQu_output;
		for(uint8 i = 0 ; i < ValueOfToken1ByQu_output.resultlen; i++) NumberValueOfToken1ByQu_input.a.set(i, ValueOfToken1ByQu_output.result.get(i));
		NumberValueOfToken1ByQu_input.len = ValueOfToken1ByQu_output.resultlen;

		CALL(BIGStringToNumber, NumberValueOfToken1ByQu_input, NumberValueOfToken1ByQu_output);

		BIGStringToNumber_input NumberValueOfToken2ByQu_input;
		BIGStringToNumber_output NumberValueOfToken2ByQu_output;
		for(uint8 i = 0 ; i < ValueOfToken2ByQu_output.resultlen; i++) NumberValueOfToken2ByQu_input.a.set(i, ValueOfToken2ByQu_output.result.get(i));
		NumberValueOfToken2ByQu_input.len = ValueOfToken2ByQu_output.resultlen;

		CALL(BIGStringToNumber, NumberValueOfToken2ByQu_input, NumberValueOfToken2ByQu_output);

		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if(qpi.invocationReward() < NumberValueOfToken1ByQu_output.result / 100) {    // lack of swap fee
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(liquidityOfToken1 <= input.AmountOfToken1) {   /// lack of liquidity for token1 in current pool 
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(NumberValueOfToken1ByQu_output.result < NumberValueOfToken2ByQu_output.result && input.AmountOfToken1 < NumberValueOfToken2ByQu_output.result / NumberValueOfToken1ByQu_output.result) { // lack of amount of token1 for 1 token2
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		/// @brief ////////////////////////////////
		//uint64 ValueOfToken1Provided = ValueOfToken1ByQu * input.AmountOfToken1; // value of token1 to be provided by swapper to current pool
		//uint64 AmountOfRefundQu = ValueOfToken1Provided % ValueOfToken2ByQu;   // amount of qu to be transferred to swapper
		//uint64 AmountOftransferredToken2 = ValueOfToken1Provided / ValueOfToken2ByQu; // amount of token2 should be transferred to swapper
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		BIGNumberToString_input AmountOfToken1_input;
		BIGNumberToString_output AmountOfToken1_output;

		AmountOfToken1_input.a = input.AmountOfToken1;

		CALL(BIGNumberToString, AmountOfToken1_input, AmountOfToken1_output);

		BIGMultiple_input ValueOfToken1Provided_input;
		BIGMultiple_output ValueOfToken1Provided_output;

		for(uint8 i = 0 ; i < ValueOfToken1ByQu_output.resultlen; i++) ValueOfToken1Provided_input.a.set(i, ValueOfToken1ByQu_output.result.get(i));
		ValueOfToken1Provided_input.alen = ValueOfToken1ByQu_output.resultlen;
		for(uint8 i = 0 ; i < AmountOfToken1_output.len; i++) ValueOfToken1Provided_input.b.set(i, AmountOfToken1_output.result.get(i));
		ValueOfToken1Provided_input.blen = AmountOfToken1_output.len;

		CALL(BIGMultiple, ValueOfToken1Provided_input, ValueOfToken1Provided_output);

		BIGModulus_input AmountOfRefundQu_input;
		BIGModulus_output AmountOfRefundQu_output;

		for(uint8 i = 0 ; i < ValueOfToken1Provided_output.resultlen; i++) AmountOfRefundQu_input.a.set(i, ValueOfToken1Provided_output.result.get(i));
		AmountOfRefundQu_input.alen = ValueOfToken1Provided_output.resultlen;
		for(uint8 i = 0 ; i < ValueOfToken2ByQu_output.resultlen; i++) AmountOfRefundQu_input.b.set(i, ValueOfToken2ByQu_output.result.get(i));
		AmountOfRefundQu_input.blen = ValueOfToken2ByQu_output.resultlen;

		CALL(BIGModulus, AmountOfRefundQu_input, AmountOfRefundQu_output);

		BIGDiv_input AmountOftransferredToken2_input;
		BIGDiv_output AmountOftransferredToken2_output;

		for(uint8 i = 0 ; i < ValueOfToken1Provided_output.resultlen; i++) AmountOftransferredToken2_input.a.set(i, ValueOfToken1Provided_output.result.get(i));
		AmountOftransferredToken2_input.alen = ValueOfToken1Provided_output.resultlen;
		for(uint8 i = 0 ; i < ValueOfToken2ByQu_output.resultlen; i++) AmountOftransferredToken2_input.b.set(i, ValueOfToken2ByQu_output.result.get(i));
		AmountOftransferredToken2_input.blen = ValueOfToken2ByQu_output.resultlen;

		CALL(BIGDiv, AmountOftransferredToken2_input, AmountOftransferredToken2_output);

		BIGStringToNumber_input NumberAmountOfRefundQu_input;
		BIGStringToNumber_output NumberAmountOfRefundQu_output;

		for(uint8 i = 0 ; i < AmountOfRefundQu_output.resultlen; i++) NumberAmountOfRefundQu_input.a.set(i, AmountOfRefundQu_output.result.get(i));
		NumberAmountOfRefundQu_input.len = AmountOfRefundQu_output.resultlen;

		CALL(BIGStringToNumber, NumberAmountOfRefundQu_input, NumberAmountOfRefundQu_output);

		BIGStringToNumber_input NumberAmountOftransferredToken2_input;
		BIGStringToNumber_output NumberAmountOftransferredToken2_output;

		for(uint8 i = 0 ; i < AmountOftransferredToken2_output.resultlen; i++) NumberAmountOftransferredToken2_input.a.set(i, AmountOftransferredToken2_output.result.get(i));
		NumberAmountOftransferredToken2_input.len = AmountOftransferredToken2_output.resultlen;

		CALL(BIGStringToNumber, NumberAmountOftransferredToken2_input, NumberAmountOftransferredToken2_output);

		if(NumberAmountOfRefundQu_output.result > pool.liquidityOfQU) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() > NumberValueOfToken1ByQu_output.result / 100) {    // refund rest fund
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - NumberValueOfToken1ByQu_output.result / 100);
		}

		qpi.transfer(qpi.invocator(), NumberAmountOfRefundQu_output.result);
		qpi.transferShareOwnershipAndPossession(token1.assetName, token1.issuer, qpi.invocator(), qpi.invocator(), input.AmountOfToken1, QPOOL_CONTRACTID);   // transfer token1 to pool
		qpi.transferShareOwnershipAndPossession(token2.assetName, token2.issuer, QPOOL_CONTRACTID, QPOOL_CONTRACTID, NumberAmountOftransferredToken2_output.result, qpi.invocator());  // transfer token2 to swapper
	_

	//cast int to uint8
	PUBLIC_PROCEDURE(BIGNumberToString)
		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) return;
		sint64 a = input.a;
		uint64 P = 1;
		output.len = 1;

		if(a < 0) {
			output.result.set(0, '-');
			output.len = 2;
			a *= -1;
		}
		while(a / 10) {
			output.len++;
			a /= 10;
			P *= 10;
		}

		a = input.a;
		if(a < 0) a *= -1;
		
		for(uint8 i = 0 ; i < (input.a < 0 ? output.len - 1: output.len); i++) {
			if(input.a < 0) output.result.set(i + 1, (a / P) + '0');
			else output.result.set(i, (a / P) + '0');
			a %= P;
			P /= 10;
		}
		for(uint8 i = 0 ; i < output.len; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.len;
	_

	// uint8 to int
    PUBLIC_PROCEDURE(BIGStringToNumber)
		if(input.len == 0) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		//when negative
		if(input.a.get(0) == 45) {     // if first element is '-'
			if(input.len > 20 || input.len < 2) {
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
			// checking if a is number
			for(uint8 i = 1 ; i < input.len; i++) {
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			if(input.len > 19 || input.len < 1) {
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
			// checking if a is number
			for(uint8 i = 0; i < input.len; i++) {
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) return;
		
		if(input.a.get(0) == 45) output.result = (input.a.get(1) - '0') * (-1);
		else output.result = input.a.get(0) - '0';

		for(uint8 i = 1 ; i < (input.a.get(0) == 45?input.len - 1:input.len); i++) {
			if(input.a.get(0) == 45) output.result = output.result * 10 - (input.a.get(i + 1) - '0');
			else output.result = output.result * 10 + (input.a.get(i) - '0');
		}
		state.BIGTest = output.result;
	_

	// Plus operator
	// BIGPlus is only available for positive input. if there is negative input, the output would be wrong result.
	PUBLIC_PROCEDURE(BIGPlus)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT * 2) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		uint8 maxlen = input.alen > input.blen ? input.alen: input.blen;
		uint8_128 tempa;
		uint8_128 tempb;
		uint8_128 tempResult;

		for(uint8 i = 0 ; i < input.alen; i++) tempa.set(i, input.a.get(input.alen - i - 1));     // reverse
		for(uint8 i = 0 ; i < input.blen; i++) tempb.set(i, input.b.get(input.blen - i - 1));     // reverse
	
		bit carry = 0;

		output.resultlen = maxlen;

		for(uint8 i = 0; i < maxlen || carry; i++) {
			uint8 sum = carry;
			if(i < input.alen) sum += tempa.get(i) - '0';
			if(i < input.blen) sum += tempb.get(i) - '0';

			carry = sum >= 10;
			if(carry) sum -= 10;
			if(i == maxlen) output.resultlen++;

			tempResult.set(i, sum + '0');
		}

		for(uint8 i = 0 ; i < output.resultlen; i++) output.result.set(i, tempResult.get(output.resultlen - i - 1));     // reverse

		for(uint8 i = 0 ; i < output.resultlen; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.resultlen;
	_

	// Minus operator   
	// BIGMinus is only available for positive result. if there is negative result, the output would be wrong result.
	PUBLIC_PROCEDURE(BIGMinus)
		// checking if the result would be positive
		if (input.blen > input.alen) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT * 2) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint8_128 tempa;
		uint8_128 tempb;
		uint8_128 tempResult;

		for(uint8 i = 0 ; i < input.alen; i++) tempa.set(i, input.a.get(input.alen - i - 1));     // reverse
		for(uint8 i = 0 ; i < input.blen; i++) tempb.set(i, input.b.get(input.blen - i - 1));     // reverse

		bit borrow = 0;
		for (uint8 i = 0; i < input.alen; i++) {
			sint8 diff = (tempa.get(i) - '0') - borrow;
			if(i < input.blen) diff -= tempb.get(i) - '0';
			if(i == input.alen - 1 && input.alen == input.blen && diff < 0) {   // checking if the result would be positive
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
			borrow =  diff < 0 ? 1 : 0;
			if(diff < 0) diff += 10;
			
			tempResult.set(i, diff + '0');
		}

		output.resultlen = input.alen;
		for(uint8 i = 0 ; i < output.resultlen; i++) output.result.set(i, tempResult.get(output.resultlen - i - 1));     // reverse

		for(uint8 i = 0 ; i < output.resultlen; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.resultlen;
	_

	// Multiple operator
	PUBLIC_PROCEDURE(BIGMultiple)
		uint8_128 tempa;
		uint8_128 tempb;
		uint8_128 tempResult;
		if(input.a.get(0) == '-') {     // when a is negative
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				tempa.set(i - 1, input.a.get(input.alen - i));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			// checking if a is number
			for(uint8 i = 0; i < input.alen; i++) {
				tempa.set(i, input.a.get(input.alen - i - 1));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(input.b.get(0) == '-') {     // when b is negative
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				tempb.set(i - 1, input.b.get(input.blen - i));
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				tempb.set(i, input.b.get(input.blen - i - 1));
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT * 4) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		for(uint8 i = 0 ; i < input.alen + input.blen; i++) tempResult.set(i, '0');
		for (uint8 i = 0; i < (input.a.get(0) == '-'? input.alen - 1: input.alen); i++) {
			uint8 carry = 0;
			for (uint8 j = 0; j < (input.b.get(0) == '-'? input.blen - 1: input.blen) || carry; j++) {
				uint8 current;
				if(input.b.get(0) == '-') {
					current = (tempResult.get(i + j) - '0') + (tempa.get(i) - '0') * (j < input.blen - 1 ? (tempb.get(j) - '0') : 0) + carry;
					if(input.a.get(0) == '-' && i == input.alen - 2 && j == input.blen - 2 && current >= 10) output.resultlen++;
					if(input.a.get(0) != '-' && i == input.alen - 1 && j == input.blen - 2 && current >= 10) output.resultlen++;
				}
				else {
					current = (tempResult.get(i + j) - '0') + (tempa.get(i) - '0') * (j < input.blen ? (tempb.get(j) - '0') : 0) + carry;
					if(input.a.get(0) == '-' && i == input.alen - 2 && j == input.blen - 1 && current >= 10) output.resultlen++;
					if(input.a.get(0) != '-' && i == input.alen - 1 && j == input.blen - 1 && current >= 10) output.resultlen++;
				}

				carry = current / 10;
				tempResult.set(i + j, (current % 10) + '0');
			}
		}

		uint8 length = 0;
		if((input.a.get(0) == 45 && input.b.get(0) != 45) || (input.a.get(0) != 45 && input.b.get(0) == 45)) {
			length = 1;
			output.result.set(0, 45);
		}
		bit zeroCheck = 0;
		for(uint8 i = 0; i < input.alen + input.blen; i++) {
			if(tempResult.get(input.alen + input.blen - i - 1) != '0' || zeroCheck) {
				zeroCheck = 1;
				output.result.set(length++, tempResult.get(input.alen + input.blen - i - 1));     // reverse
			}
		}
		output.resultlen = length;
		for(uint8 i = 0 ; i < output.resultlen; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.resultlen;
	_
	// Div operator
	PUBLIC_PROCEDURE(BIGDiv)
		uint8_128 tempa;
		uint8_128 tempb;
		uint8_128 tempResult;
		bit sign = 0;
		if(input.a.get(0) == '-') {     // when a is negative
			sign ^= 1;
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				tempa.set(i - 1, input.a.get(i - 1));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			// checking if a is number
			for(uint8 i = 0; i < input.alen; i++) {
				tempa.set(i, input.a.get(i));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(input.b.get(0) == '-') {     // when b is negative
			sign ^= 1;
			uint8 zeroCount = 0;
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				tempb.set(i - 1, input.b.get(i));
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}

			if(zeroCount == input.blen - 1) {             //  div by zoro
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			uint8 zeroCount = 0;
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				tempb.set(i, input.b.get(i));
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}

			if(zeroCount == input.blen) {             //  div by zoro
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT * 4) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}


		uint8_128 current;
		uint8 currentLen = 0;
		for (uint8 i = 0; i < (input.alen == '-' ? input.alen - 1: input.alen); i++) {
			current.set(currentLen++, tempa.get(i));
			uint8 count = 0;
			BIGBigOrEqualComparison_input compInput;
			BIGBigOrEqualComparison_output compOutput;
			for(uint8 j = 0 ; j < currentLen; j++) compInput.a.set(j, current.get(j));
			compInput.alen = currentLen;
			for(uint8 j = 0 ; j < (input.blen == '-' ? input.blen - 1: input.blen); j++) compInput.b.set(j, tempb.get(j));
			compInput.blen = (input.blen == '-' ? input.blen - 1: input.blen);
			CALL(BIGBigOrEqualComparison, compInput, compOutput);

			while (compOutput.result) {
				BIGMinus_input MinusInput;
				BIGMinus_output MinusOutput;
				for(uint8 j = 0 ; j < currentLen; j++) MinusInput.a.set(j, current.get(j));
				MinusInput.alen = currentLen;
				for(uint8 j = 0 ; j < (input.blen == '-' ? input.blen - 1: input.blen); j++) MinusInput.b.set(j, tempb.get(j));
				MinusInput.blen = (input.blen == '-' ? input.blen - 1: input.blen);
				
				CALL(BIGMinus, MinusInput, MinusOutput);
				for(uint8 j = 0 ; j < output.resultlen; j++) current.set(j, MinusOutput.result.get(j));
				count++;
			}
			tempResult.set(i, count + '0');
		}

		output.resultlen = 0;

		if(sign) {
			output.result.set(0, '-');
			output.resultlen = 1;
			bit flag = 0;
			for(uint8 i = 1 ; i < input.alen; i++) {
				if(tempResult.get(i) != '0' || flag) {
					flag = 1;
					output.result.set(output.resultlen++, tempResult.get(i));
				}
			}
		}
		else {
			bit flag = 0;
			for(uint8 i = 0; i < input.alen; i++) {
				if(tempResult.get(i) != '0' || flag) {
					flag = 1;
					output.result.set(output.resultlen++, tempResult.get(i));
				}
			}
		}

		for(uint8 i = 0 ; i < output.resultlen; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.resultlen;
	_

	// BIGModulus a % b
	PUBLIC_PROCEDURE(BIGModulus)
		uint8_128 tempa;
		uint8_128 tempb;
		uint8_128 tempResult;
		bit sign = 0;
		if(input.a.get(0) == '-') {     // when a is negative
			sign ^= 1;
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				tempa.set(i - 1, input.a.get(i - 1));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			// checking if a is number
			for(uint8 i = 0; i < input.alen; i++) {
				tempa.set(i, input.a.get(i));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(input.b.get(0) == '-') {     // when b is negative
			sign ^= 1;
			uint8 zeroCount = 0;
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				tempb.set(i - 1, input.b.get(i));
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}

			if(zeroCount == input.blen - 1) {             //  div by zoro
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}
		else {                // when positive
			uint8 zeroCount = 0;
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				tempb.set(i, input.b.get(i));
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}

			if(zeroCount == input.blen) {             //  div by zoro
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT * 4) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}


		uint8_128 current;
		uint8 currentLen = 0;
		for (uint8 i = 0; i < (input.alen == '-' ? input.alen - 1: input.alen); i++) {
			current.set(currentLen++, tempa.get(i));
			uint8 count = 0;
			BIGBigOrEqualComparison_input compInput;
			BIGBigOrEqualComparison_output compOutput;
			for(uint8 j = 0 ; j < currentLen; j++) compInput.a.set(j, current.get(j));
			compInput.alen = currentLen;
			for(uint8 j = 0 ; j < (input.blen == '-' ? input.blen - 1: input.blen); j++) compInput.b.set(j, tempb.get(j));
			compInput.blen = (input.blen == '-' ? input.blen - 1: input.blen);
			CALL(BIGBigOrEqualComparison, compInput, compOutput);

			while (compOutput.result) {
				BIGMinus_input MinusInput;
				BIGMinus_output MinusOutput;
				for(uint8 j = 0 ; j < currentLen; j++) MinusInput.a.set(j, current.get(j));
				MinusInput.alen = currentLen;
				for(uint8 j = 0 ; j < (input.blen == '-' ? input.blen - 1: input.blen); j++) MinusInput.b.set(j, tempb.get(j));
				MinusInput.blen = (input.blen == '-' ? input.blen - 1: input.blen);
				
				CALL(BIGMinus, MinusInput, MinusOutput);
				for(uint8 j = 0 ; j < output.resultlen; j++) current.set(j, MinusOutput.result.get(j));
				count++;
			}
			tempResult.set(i, count + '0');
		}

		output.resultlen = 0;

		if(sign) {
			output.result.set(0, '-');
			output.resultlen = 1;
			bit flag = 0;
			for(uint8 i = 0 ; i < currentLen; i++) {
				if(current.get(i) != '0' || flag) {
					flag = 1;
					output.result.set(output.resultlen++, current.get(i));
				}
			}
		}
		else {
			bit flag = 0;
			for(uint8 i = 0; i < currentLen; i++) {
				if(current.get(i) != '0' || flag) {
					flag = 1;
					output.result.set(output.resultlen++, current.get(i));
				}
			}
		}

		for(uint8 i = 0 ; i < output.resultlen; i++) state.BIGStringNumber.set(i, output.result.get(i));
		state.BIGStringNumberLen = output.resultlen;
	_

	// BIGBigOrEqualComparison  exactly >=
	// BIGBigOrEqualComparison is only available for positive input
	PUBLIC_PROCEDURE(BIGBigOrEqualComparison)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		uint8 tlena = input.alen;
		uint8 tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') tlenb--;
			else break;
		}
		if(tlena > tlenb) output.result = 0;
		else if(tlena < tlenb) output.result = 1;
		else {
			for(uint8 i = 0 ; i < tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 0; return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 1; return;
				}
			}
			output.result = 0;
		}

		state.BIGTestComparisonResult = output.result;
	_

	// BIGSmallOrEqualComparison  exactly <=
	// BIGSmallOrEqualComparison is only available for positive input
	PUBLIC_PROCEDURE(BIGSmallOrEqualComparison)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint8 tlena = input.alen;
		uint8 tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') tlenb--;
			else break;
		}
		if(tlena > tlenb) output.result = 1;
		else if(tlena < tlenb) output.result = 0;
		else {
			for(uint8 i = 0 ; i < tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 1; return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 0; return;
				}
			}
			output.result = 0;
		}
		state.BIGTestComparisonResult = output.result;
	_

	// BIGBigComparison  exactly >
	// BIGBigComparison is only available for positive input
	PUBLIC_PROCEDURE(BIGBigComparison)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint8 tlena = input.alen;
		uint8 tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') tlenb--;
			else break;
		}
		if(tlena > tlenb) output.result = 0;
		else if(tlena < tlenb) output.result = 1;
		else {
			for(uint8 i = 0 ; i < tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 0; return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 1; return;
				}
			}
			output.result = 1;
		}

		state.BIGTestComparisonResult = output.result;
	_

	// BIGSmallComparison  exactly <
	// BIGSmallComparison is only available for positive input
	PUBLIC_PROCEDURE(BIGSmallComparison)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		if(qpi.invocationReward() < QPOOL_MULTIPRECISION_FEE_UNIT) {
			if (qpi.invocationReward() > 0)
			{
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return;
		}

		uint8 tlena = input.alen;
		uint8 tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') tlenb--;
			else break;
		}
		if(tlena > tlenb) output.result = 1;
		else if(tlena < tlenb) output.result = 0;
		else {
			for(uint8 i = 0 ; i < tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 1; return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 0; return;
				}
			}
			output.result = 1;
		}

		state.BIGTestComparisonResult = output.result;
	_

	PUBLIC_FUNCTION(GetBIGStatus)
		output.BIGTest = state.BIGTest;
		output.BIGStringNumberLen = state.BIGStringNumberLen;
		for(uint8 i = 0 ; i < output.BIGStringNumberLen; i++) output.BIGStringNumber.set(i, state.BIGStringNumber.get(i));
		output.BIGTestComparisonResult = state.BIGTestComparisonResult;
	_

	REGISTER_USER_FUNCTIONS_AND_PROCEDURES
		REGISTER_USER_FUNCTION(GetNumberOfEnableToken, 1);
		REGISTER_USER_FUNCTION(GetEnableToken, 2);
		REGISTER_USER_FUNCTION(PoolList, 3);
		REGISTER_USER_FUNCTION(GetValueOfToken, 4);
		REGISTER_USER_FUNCTION(GetBIGStatus, 5);

		REGISTER_USER_PROCEDURE(CreateLiquidityPool, 1);
		REGISTER_USER_PROCEDURE(IssueAsset, 2);
		REGISTER_USER_PROCEDURE(EnableToken, 3);
		REGISTER_USER_PROCEDURE(Swap, 4);
		REGISTER_USER_PROCEDURE(BIGNumberToString, 10);
		REGISTER_USER_PROCEDURE(BIGStringToNumber, 11);
		REGISTER_USER_PROCEDURE(BIGPlus, 12);
		REGISTER_USER_PROCEDURE(BIGMinus, 13);
		REGISTER_USER_PROCEDURE(BIGMultiple, 14);
		REGISTER_USER_PROCEDURE(BIGDiv, 15);
		REGISTER_USER_PROCEDURE(BIGModulus, 16);
		REGISTER_USER_PROCEDURE(BIGBigOrEqualComparison, 17);
		REGISTER_USER_PROCEDURE(BIGSmallOrEqualComparison, 18);
		REGISTER_USER_PROCEDURE(BIGBigComparison, 19);
		REGISTER_USER_PROCEDURE(BIGSmallComparison, 20);
	_
	INITIALIZE

		state._NumberOfPool = 0;
		state._NumberOfTotalUser = 0;
		state._NumberOfEnableToken = 1;
		_tokenInfor QwalletToken;
		QwalletToken.assetName = QPOOL_QWALLET_TOKEN;
		QwalletToken.issuer = QPOOL_ISSUER_QWALLET;
		state._TokenList.set(0, QwalletToken);
	_

	BEGIN_EPOCH
	_

	END_EPOCH
	_

	BEGIN_TICK
	_

	END_TICK
	_

	EXPAND 
	_
};