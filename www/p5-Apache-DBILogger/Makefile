# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:55 jlam Exp $
#

DISTNAME=	Apache-DBILogger-0.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://ask.netcetera.dk/
COMMENT=	Database-independent httpd database logging module

DEPENDS+=	p5-Apache-DBILogConfig-[0-9]*:../../www/p5-Apache-DBILogConfig
DEPENDS+=	ap-DBI-[0-9]*:../../www/ap-DBI

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/DBILogger/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
