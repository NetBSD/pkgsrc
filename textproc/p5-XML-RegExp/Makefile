# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:44 veego Exp $
#

DISTNAME=	XML-RegExp-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xre
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/TJMATHER/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provide regular expressions for some XML tokens

CONFLICTS+=	p5-libxml-enno-[0-9]*

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/RegExp/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
