# $NetBSD: Makefile,v 1.1.1.1 2004/05/29 01:42:39 xtraeme Exp $
#

DISTNAME=	XML-LibXML-Iterator-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Iterator for XML::LibXML parsed documents

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter

USE_BUILDLINK3= yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/LibXML/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
