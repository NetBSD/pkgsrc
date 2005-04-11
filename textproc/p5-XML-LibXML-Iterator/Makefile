# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:39 tv Exp $
#

DISTNAME=	XML-LibXML-Iterator-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlx
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Iterator for XML::LibXML parsed documents

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/LibXML/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
