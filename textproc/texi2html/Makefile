# $NetBSD: Makefile,v 1.49 2022/06/28 11:36:50 wiz Exp $

DISTNAME=	texi2html-5.0
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	http://savannah.nongnu.org/download/texi2html/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/texi2html/
COMMENT=	Texinfo-to-HTML direct translator
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

REPLACE_PERL+=	MySimple.pm
REPLACE_PERL+=	T2h_i18n.pm
REPLACE_PERL+=	T2h_l2h.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Base.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Can.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Fetch.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Makefile.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Metadata.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/Win32.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/inc/Module/Install/WriteAll.pm
REPLACE_PERL+=	lib/Unicode-EastAsianWidth/lib/Unicode/EastAsianWidth.pm
REPLACE_PERL+=	test/formatting/res/block_EOL_tex/block_EOL-l2h_cache.pm
REPLACE_PERL+=	test/formatting/res/tex/tex-l2h_cache.pm
REPLACE_PERL+=	test/formatting/res/tex_l2h_mediawiki/tex-l2h_cache.pm
REPLACE_PERL+=	test/formatting/res_all/tex_l2h_mediawiki/tex-l2h_cache.pm
REPLACE_PERL+=	test/invalid/res/math_not_closed/math_not_closed-l2h_cache.pm
REPLACE_PERL+=	test/invalid/res/tex_in_copying/tex_in_copying-l2h_cache.pm
REPLACE_PERL+=	test/invalid/res/tex_not_closed/tex_not_closed-l2h_cache.pm
REPLACE_PERL+=	test/many_input_files/tex_l2h_res/mini_ker-l2h_cache.pm
REPLACE_PERL+=	test/many_input_files/tex_l2h_res/tex-l2h_cache.pm
REPLACE_PERL+=	test/misc/res/mini_ker_l2h/mini_ker-l2h_cache.pm

.include "../../mk/bsd.pkg.mk"
