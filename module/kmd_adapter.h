#pragma once

namespace Crystal
{
	////////////////////////////////////////////////////////////////////////////////
	class KmdAdapter
	{
	public:
		using ptr_t = std::shared_ptr<KmdAdapter>;

		KmdAdapter( D3DKMT_HANDLE handle );

		~KmdAdapter();

		D3DKMT_HANDLE	GetHandle();

	private:

		D3DKMT_HANDLE	m_Handle;
	};

	////////////////////////////////////////////////////////////////////////////////
	class KmdAdapterManager
	{
	public:
		KmdAdapterManager();

		~KmdAdapterManager();

		template< typename ... ParamsT >
		KmdAdapter::ptr_t& CreateAdapter( ParamsT&&... p );

	private:

		static D3DKMT_HANDLE ListIndexToKmtHandle( uint32_t i );
		static uint32_t KmtHandleToListIndex( D3DKMT_HANDLE handle );

		std::vector<KmdAdapter::ptr_t> m_Adapters;
	};

	////////////////////////////////////////////////////////////////////////////////
	template< typename... ParamsT >
	KmdAdapter::ptr_t& KmdAdapterManager::CreateAdapter( ParamsT&&... p )
	{
		m_Adapters.emplace_back(
			std::move( std::make_shared<KmdAdapter>(
				ListIndexToKmtHandle( m_Adapters.size() ),
				std::forward<ParamsT>( p )... ) ) );

		return m_Adapters.back();
	}
}