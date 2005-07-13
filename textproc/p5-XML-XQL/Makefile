# $NetBSD: Makefile,v 1.16 2005/07/13 18:01:44 jlam Exp $
#

DISTNAME=	XML-XQL-0.68
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xxq
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module to perform XQL queries on XML object trees

DEPENDS+=	p5-XML-DOM>=1.29:../p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.30:../p5-XML-Parser
DEPENDS+=	p5-Date-Manip>=5.33:../../devel/p5-Date-Manip
DEPENDS+=	p5-Parse-Yapp-[0-9]*:../../devel/p5-Parse-Yapp
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

CONFLICTS+=	p5-libxml-enno-[0-9]*

PERL5_PACKLIST=		auto/XML/XQL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
