# $NetBSD: Makefile,v 1.9 2003/03/29 12:42:39 jmmv Exp $

DISTNAME=	libxml-enno-1.05a
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lxe
WRKSRC=		${WRKDIR}/libxml-enno-1.05
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.erols.com/enno/
COMMENT=	Several XML manipulation tools, including XML::DOM

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-libwww>=5.50:../../www/p5-libwww
DEPENDS+=	p5-libxml>=0.07:../../textproc/p5-libxml
DEPENDS+=	p5-Parse-Yapp>=1.04:../../devel/p5-Parse-Yapp

CONFLICTS+=	p5-XML-DOM-[0-9]* p5-XML-XQL-[0-9]*
CONFLICTS+=	p5-XML-Checker-[0-9]* p5-XML-RegExp-[0-9]*

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/libxml-enno/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
