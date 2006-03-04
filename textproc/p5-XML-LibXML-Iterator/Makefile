# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:49 jlam Exp $
#

DISTNAME=	XML-LibXML-Iterator-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Iterator for XML::LibXML parsed documents

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter

PERL5_PACKLIST=	auto/XML/LibXML/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
