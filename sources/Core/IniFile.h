#pragma once

// refs
class	CIniFile;
struct xr_token;


//-----------------------------------------------------------------------------------------------------------
//�������� Inifile
//-----------------------------------------------------------------------------------------------------------

class CORE_API CIniFile
{
public:
	struct CORE_API	Item
	{
		shared_str	first;
		shared_str	second;

#ifdef DEBUG
		shared_str	comment;
#endif // DEBUG

		Item() : first(0), second(0)

#ifdef DEBUG
			, comment(0)
#endif // DEBUG

		{};
	};
	typedef xr_vector<Item>				Items;
	typedef Items::const_iterator		SectCIt;
	typedef Items::iterator				SectIt_;
    struct CORE_API	Sect {
		shared_str		Name;
		Items			Data;

//.		IC SectCIt		begin()		{ return Data.begin();	}
//.		IC SectCIt		end()		{ return Data.end();	}
//.		IC size_t		size()		{ return Data.size();	}
//.		IC void			clear()		{ Data.clear();			}
	    BOOL			line_exist	(const char* L, const char** val=0);
	};
	typedef	xr_vector<Sect*>		Root;
	typedef Root::iterator			RootIt;

	// factorisation
	static CIniFile*	Create		(const char* szFileName, BOOL ReadOnly=TRUE);
	static void			Destroy		(CIniFile*);
    static IC BOOL		IsBOOL		(const char* B)	{ return (xr_strcmp(B,"on")==0 || xr_strcmp(B,"yes")==0 || xr_strcmp(B,"true")==0 || xr_strcmp(B,"1")==0);}
private:
	char* fName;
	Root		DATA;
	BOOL		bReadOnly;
	void		Load			(IReader* F, const char* path);
public:
    BOOL		bSaveAtEnd;
public:
	CIniFile( IReader* F, const char* path=0 );
	CIniFile(const char* szFileName, BOOL ReadOnly=TRUE, BOOL bLoadAtStart=TRUE, BOOL SaveAtEnd=TRUE);
	virtual 	~CIniFile( );
    bool		save_as         (const char* new_fname=0 );

	const char* fname			( ) { return fName; };

	Sect&		r_section		(const char* S			);
	Sect&		r_section		( const shared_str& S	);
	BOOL		line_exist		(const char* S, const char* L );
	BOOL		line_exist		( const shared_str& S, const shared_str& L );
	u32			line_count		(const char* S			);
	u32			line_count		( const shared_str& S	);
	BOOL		section_exist	(const char* S			);
	BOOL		section_exist	( const shared_str& S	);
	Root&		sections		( ){return DATA;}

	CLASS_ID	r_clsid			(const char* S, const char* L );
	CLASS_ID	r_clsid			( const shared_str& S, const char* L )				{ return r_clsid(*S,L);			}
	const char* r_string		(const char* S, const char* L);															// ��������� �������
	const char* r_string		( const shared_str& S, const char* L)				{ return r_string(*S,L);		}	// ��������� �������
	shared_str		r_string_wb		(const char* S, const char* L);															// ������� �������
	shared_str		r_string_wb		( const shared_str& S, const char* L)				{ return r_string_wb(*S,L);		}	// ������� �������
	u8	 		r_u8			(const char* S, const char* L );
	u8	 		r_u8			( const shared_str& S, const char* L )				{ return r_u8(*S,L);			}
	u16	 		r_u16			(const char* S, const char* L );
	u16	 		r_u16			( const shared_str& S, const char* L )				{ return r_u16(*S,L);			}
	u32	 		r_u32			(const char* S, const char* L );
	u32	 		r_u32			( const shared_str& S, const char* L )				{ return r_u32(*S,L);			}
	s8	 		r_s8			(const char* S, const char* L );
	s8	 		r_s8			( const shared_str& S, const char* L )				{ return r_s8(*S,L);			}
	s16	 		r_s16			(const char* S, const char* L );
	s16	 		r_s16			( const shared_str& S, const char* L )				{ return r_s16(*S,L);			}
	int	 		r_s32			(const char* S, const char* L );
	int	 		r_s32			( const shared_str& S, const char* L )				{ return r_s32(*S,L);			}
	float		r_float			(const char* S, const char* L );
	float		r_float			( const shared_str& S, const char* L )				{ return r_float(*S,L);			}
	Fcolor		r_fcolor		(const char* S, const char* L );
	Fcolor		r_fcolor		( const shared_str& S, const char* L )				{ return r_fcolor(*S,L);		}
	u32			r_color			(const char* S, const char* L );
	u32			r_color			( const shared_str& S, const char* L )				{ return r_color(*S,L);			}
	Ivector2	r_ivector2		(const char* S, const char* L );
	Ivector2	r_ivector2		( const shared_str& S, const char* L )				{ return r_ivector2(*S,L);		}
	Ivector3	r_ivector3		(const char* S, const char* L );
	Ivector3	r_ivector3		( const shared_str& S, const char* L )				{ return r_ivector3(*S,L);		}
	Ivector4	r_ivector4		(const char* S, const char* L );
	Ivector4	r_ivector4		( const shared_str& S, const char* L )				{ return r_ivector4(*S,L);		}
	Fvector2	r_fvector2		(const char* S, const char* L );
	Fvector2	r_fvector2		( const shared_str& S, const char* L )				{ return r_fvector2(*S,L);		}
	Fvector3	r_fvector3		(const char* S, const char* L );
	Fvector3	r_fvector3		( const shared_str& S, const char* L )				{ return r_fvector3(*S,L);		}
	Fvector4	r_fvector4		(const char* S, const char* L );
	Fvector4	r_fvector4		( const shared_str& S, const char* L )				{ return r_fvector4(*S,L);		}
	BOOL		r_bool			(const char* S, const char* L );
	BOOL		r_bool			( const shared_str& S, const char* L )				{ return r_bool(*S,L);			}
	int			r_token			(const char* S, const char* L, const xr_token* token_list);
	BOOL		r_line			(const char* S, int L, const char** N, const char** V );
	BOOL		r_line			( const shared_str& S, int L, const char** N, const char** V );

    void		w_string		(const char* S, const char* L, const char* V, const char* comment=0 );
	void		w_u8			(const char* S, const char* L, u8				V, const char* comment=0 );
	void		w_u16			(const char* S, const char* L, u16				V, const char* comment=0 );
	void		w_u32			(const char* S, const char* L, u32				V, const char* comment=0 );
    void		w_s8			(const char* S, const char* L, s8				V, const char* comment=0 );
	void		w_s16			(const char* S, const char* L, s16				V, const char* comment=0 );
	void		w_s32			(const char* S, const char* L, int				V, const char* comment=0 );
	void		w_float			(const char* S, const char* L, float				V, const char* comment=0 );
    void		w_fcolor		(const char* S, const char* L, const Fcolor&		V, const char* comment=0 );
    void		w_color			(const char* S, const char* L, u32				V, const char* comment=0 );
    void		w_ivector2		(const char* S, const char* L, const Ivector2&	V, const char* comment=0 );
	void		w_ivector3		(const char* S, const char* L, const Ivector3&	V, const char* comment=0 );
	void		w_ivector4		(const char* S, const char* L, const Ivector4&	V, const char* comment=0 );
	void		w_fvector2		(const char* S, const char* L, const Fvector2&	V, const char* comment=0 );
	void		w_fvector3		(const char* S, const char* L, const Fvector3&	V, const char* comment=0 );
	void		w_fvector4		(const char* S, const char* L, const Fvector4&	V, const char* comment=0 );
	void		w_bool			(const char* S, const char* L, BOOL				V, const char* comment=0 );

    void		remove_line		(const char* S, const char* L );
};

// Main configuration file
extern CORE_API CIniFile* pSettings;
