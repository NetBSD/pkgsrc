# $NetBSD: Makefile,v 1.1.1.1 2001/10/01 02:12:59 jlam Exp $

DISTNAME=	Apache-SSI-2.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to implement Server Side Includes

DEPENDS+=	ap-perl>=1.19:../../www/ap-perl
DEPENDS+=	p5-HTML-SimpleParse>=0.06:../../www/p5-HTML-SimpleParse

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/SSI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
