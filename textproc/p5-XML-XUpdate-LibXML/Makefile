# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:38 wiz Exp $
#

DISTNAME=	XML-XUpdate-LibXML-0.2.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/XUpdate/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
