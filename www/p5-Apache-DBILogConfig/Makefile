# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:54 jlam Exp $
#

DISTNAME=	Apache-DBILogConfig-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
COMMENT=	A database-independent Apache database logger

DEPENDS+=	ap-DBI-[0-9]*:../../www/ap-DBI
DEPENDS+=	p5-TimeDate-[0-9]*:../../devel/p5-TimeDate

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/DBILogConfig/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
