using namespace QPI;

#define QPOOL_INITIAL_QPT 1000
#define QPOOL_MAX_NUMBER_OF_POOL 128
#define QPOOL_FEE_CREATE_POOL 100000000LL
#define QPOOL_FEE_ISSUE_ASSET 1000000000LL
#define QPOOL_TOKEN_TRANSER_FEE 1000LL // Amount of qus
#define QPOOL_ENABLE_TOKEN_FEE 100000000LL
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
	uint64_16777216 _QPTAmountOfUser; // Amount of LP token of nth user in Qpool
	id_16777216 _UserID;	   // The id of nth user in Qpool
	uint8_16777216 _PoolNumberOfUser;     // The number of pool user provided
	uint32 _NumberOfTotalUser;

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
		uint8 QuWeight = 100 - input.Weight1 - input.Weight2 - input.Weight3 - input.Weight4 - input.WeightOfQWALLET;

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

	REGISTER_USER_FUNCTIONS_AND_PROCEDURES
		REGISTER_USER_FUNCTION(GetNumberOfEnableToken, 1);
		REGISTER_USER_FUNCTION(GetEnableToken, 2);
		REGISTER_USER_FUNCTION(PoolList, 3);

		REGISTER_USER_PROCEDURE(CreateLiquidityPool, 1);
		REGISTER_USER_PROCEDURE(IssueAsset, 2);
		REGISTER_USER_PROCEDURE(EnableToken, 3);
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