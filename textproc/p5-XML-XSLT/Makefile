# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:45 veego Exp $

DISTNAME=	XML-XSLT-0.32
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxs
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for processing XSLT

DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/XSLT/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
