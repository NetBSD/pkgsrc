# $NetBSD: Makefile,v 1.4 2002/10/27 20:49:01 seb Exp $

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

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/XSLT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
