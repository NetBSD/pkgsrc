# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:40 tv Exp $
#

DISTNAME=	XML-XUpdate-LibXML-0.2.3
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlx
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/XUpdate/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
