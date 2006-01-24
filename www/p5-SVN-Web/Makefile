# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:49 wiz Exp $

DISTNAME=	SVN-Web-0.41
PKGNAME=	p5-${DISTNAME}
# PKGREVISION=	4
PKGREVISION=	1
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NIKC/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Unstable snapshot of Subversion repository browser

TEX_ACCEPTED=	teTeX1 teTeX2 teTeX3

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-Date-Calc>=4.3:../../devel/p5-Date-Calc
DEPENDS+=	p5-DBI>=1.18:../../databases/p5-DBI
DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph3d>=0.55:../../graphics/p5-GDGraph3d
DEPENDS+=	p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-Locale-Maketext-Lexicon-[0-9]*:../../misc/p5-Locale-Maketext-Lexicon
DEPENDS+=	p5-Locale-Maketext-Simple-[0-9]*:../../misc/p5-Locale-Maketext-Simple
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Plugin-Number-Format>=1.01:../../textproc/p5-Template-Plugin-Number-Format
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-Text-Diff-HTML>=0.04:../../textproc/p5-Text-Diff-HTML
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM
DEPENDS+=	p5-subversion>=0.32.1:../../devel/p5-subversion
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-DOM>=1.43:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-RSS>=0.9:../../textproc/p5-XML-RSS
DEPENDS+=	p5-XML-XPath>=1.08:../../textproc/p5-XML-XPath
DEPENDS+=	p5-XML-RSS>=0.97:../../textproc/p5-XML-RSS
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

# TODO: Recommends:
#        Template::Plugin::Clickable
#        Template::Plugin::Clickable::Email
#        Template::Plugin::Subst

PERL5_PACKLIST=		auto/SVN/Web/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
