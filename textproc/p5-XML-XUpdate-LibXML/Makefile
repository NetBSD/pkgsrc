# $NetBSD: Makefile,v 1.21 2017/06/05 14:25:00 ryoon Exp $
#

DISTNAME=	XML-XUpdate-LibXML-0.6.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-XUpdate-LibXML/
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

DEPENDS+=	p5-XML-LibXML>=1.54:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-LibXML-Iterator-[0-9]*:../../textproc/p5-XML-LibXML-Iterator

PERL5_PACKLIST=	auto/XML/XUpdate/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
